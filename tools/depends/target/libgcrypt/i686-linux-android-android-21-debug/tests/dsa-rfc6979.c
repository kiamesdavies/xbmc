/* dsa-rfc6979.c - Test for Deterministic DSA
 * Copyright (C) 2008 Free Software Foundation, Inc.
 * Copyright (C) 2013 g10 Code GmbH
 *
 * This file is part of Libgcrypt.
 *
 * Libgcrypt is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * Libgcrypt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#ifdef _GCRYPT_IN_LIBGCRYPT
# include "../src/gcrypt-int.h"
#else
# include <gcrypt.h>
#endif


#define my_isascii(c) (!((c) & 0x80))
#define digitp(p)   (*(p) >= '0' && *(p) <= '9')
#define hexdigitp(a) (digitp (a)                     \
                      || (*(a) >= 'A' && *(a) <= 'F')  \
                      || (*(a) >= 'a' && *(a) <= 'f'))
#define xtoi_1(p)   (*(p) <= '9'? (*(p)- '0'): \
                     *(p) <= 'F'? (*(p)-'A'+10):(*(p)-'a'+10))
#define xtoi_2(p)   ((xtoi_1(p) * 16) + xtoi_1((p)+1))
#define DIM(v)		     (sizeof(v)/sizeof((v)[0]))
#define DIMof(type,member)   DIM(((type *)0)->member)

static int verbose;
static int error_count;

static void
info (const char *format, ...)
{
  va_list arg_ptr;

  va_start (arg_ptr, format);
  vfprintf (stderr, format, arg_ptr);
  va_end (arg_ptr);
}

static void
fail (const char *format, ...)
{
  va_list arg_ptr;

  va_start (arg_ptr, format);
  vfprintf (stderr, format, arg_ptr);
  va_end (arg_ptr);
  error_count++;
}

static void
die (const char *format, ...)
{
  va_list arg_ptr;

  va_start (arg_ptr, format);
  vfprintf (stderr, format, arg_ptr);
  va_end (arg_ptr);
  exit (1);
}

static void
show_sexp (const char *prefix, gcry_sexp_t a)
{
  char *buf;
  size_t size;

  if (prefix)
    fputs (prefix, stderr);
  size = gcry_sexp_sprint (a, GCRYSEXP_FMT_ADVANCED, NULL, 0);
  buf = gcry_xmalloc (size);

  gcry_sexp_sprint (a, GCRYSEXP_FMT_ADVANCED, buf, size);
  fprintf (stderr, "%.*s", (int)size, buf);
  gcry_free (buf);
}


/* Convert STRING consisting of hex characters into its binary
   representation and return it as an allocated buffer. The valid
   length of the buffer is returned at R_LENGTH.  The string is
   delimited by end of string.  The function returns NULL on
   error.  */
static void *
data_from_hex (const char *string, size_t *r_length)
{
  const char *s;
  unsigned char *buffer;
  size_t length;

  buffer = gcry_xmalloc (strlen(string)/2+1);
  length = 0;
  for (s=string; *s; s +=2 )
    {
      if (!hexdigitp (s) || !hexdigitp (s+1))
        die ("error parsing hex string `%s'\n", string);
      ((unsigned char*)buffer)[length++] = xtoi_2 (s);
    }
  *r_length = length;
  return buffer;
}


static void
extract_cmp_data (gcry_sexp_t sexp, const char *name, const char *expected)
{
  gcry_sexp_t l1;
  const void *a;
  size_t alen;
  void *b;
  size_t blen;

  l1 = gcry_sexp_find_token (sexp, name, 0);
  a = gcry_sexp_nth_data (l1, 1, &alen);
  b = data_from_hex (expected, &blen);
  if (!a)
    fail ("parameter \"%s\" missing in key\n", name);
  else if ( alen != blen || memcmp (a, b, alen) )
    {
      fail ("parameter \"%s\" does not match expected value\n", name);
      if (verbose)
        {
          info ("expected: %s\n", expected);
          show_sexp ("sexp: ", sexp);
        }
    }
  gcry_free (b);
  gcry_sexp_release (l1);
}


/* These test vectors are from RFC 6979.  */
static void
check_dsa_rfc6979 (void)
{
  static struct {
    const char *name;
    const char *key;
  } keys[] = {
    {
      "DSA, 1024 bits",
      "(private-key"
      " (DSA"
      " (p #86F5CA03DCFEB225063FF830A0C769B9DD9D6153AD91D7CE27F787C43278B447"
      "     E6533B86B18BED6E8A48B784A14C252C5BE0DBF60B86D6385BD2F12FB763ED88"
      "     73ABFD3F5BA2E0A8C0A59082EAC056935E529DAF7C610467899C77ADEDFC846C"
      "     881870B7B19B2B58F9BE0521A17002E3BDD6B86685EE90B3D9A1B02B782B1779#)"
      " (q #996F967F6C8E388D9E28D01E205FBA957A5698B1#)"
      " (g #07B0F92546150B62514BB771E2A0C0CE387F03BDA6C56B505209FF25FD3C133D"
      "     89BBCD97E904E09114D9A7DEFDEADFC9078EA544D2E401AEECC40BB9FBBF78FD"
      "     87995A10A1C27CB7789B594BA7EFB5C4326A9FE59A070E136DB77175464ADCA4"
      "     17BE5DCE2F40D10A46A3A3943F26AB7FD9C0398FF8C76EE0A56826A8A88F1DBD#)"
      " (x #411602CB19A6CCC34494D79D98EF1E7ED5AF25F7#)"
      " (y #5DF5E01DED31D0297E274E1691C192FE5868FEF9E19A84776454B100CF16F653"
      "     92195A38B90523E2542EE61871C0440CB87C322FC4B4D2EC5E1E7EC766E1BE8D"
      "     4CE935437DC11C3C8FD426338933EBFE739CB3465F4D3668C5E473508253B1E6"
      "     82F65CBDC4FAE93C2EA212390E54905A86E2223170B44EAA7DA5DD9FFCFB7F3B#)"
      " ))"
    },
    {
      "DSA, 2048 bits",
      "(private-key"
      " (DSA"
      " (p #9DB6FB5951B66BB6FE1E140F1D2CE5502374161FD6538DF1648218642F0B5C48"
      "     C8F7A41AADFA187324B87674FA1822B00F1ECF8136943D7C55757264E5A1A44F"
      "     FE012E9936E00C1D3E9310B01C7D179805D3058B2A9F4BB6F9716BFE6117C6B5"
      "     B3CC4D9BE341104AD4A80AD6C94E005F4B993E14F091EB51743BF33050C38DE2"
      "     35567E1B34C3D6A5C0CEAA1A0F368213C3D19843D0B4B09DCB9FC72D39C8DE41"
      "     F1BF14D4BB4563CA28371621CAD3324B6A2D392145BEBFAC748805236F5CA2FE"
      "     92B871CD8F9C36D3292B5509CA8CAA77A2ADFC7BFD77DDA6F71125A7456FEA15"
      "     3E433256A2261C6A06ED3693797E7995FAD5AABBCFBE3EDA2741E375404AE25B#)"
      " (q #F2C3119374CE76C9356990B465374A17F23F9ED35089BD969F61C6DDE9998C1F#)"
      " (g #5C7FF6B06F8F143FE8288433493E4769C4D988ACE5BE25A0E24809670716C613"
      "     D7B0CEE6932F8FAA7C44D2CB24523DA53FBE4F6EC3595892D1AA58C4328A06C4"
      "     6A15662E7EAA703A1DECF8BBB2D05DBE2EB956C142A338661D10461C0D135472"
      "     085057F3494309FFA73C611F78B32ADBB5740C361C9F35BE90997DB2014E2EF5"
      "     AA61782F52ABEB8BD6432C4DD097BC5423B285DAFB60DC364E8161F4A2A35ACA"
      "     3A10B1C4D203CC76A470A33AFDCBDD92959859ABD8B56E1725252D78EAC66E71"
      "     BA9AE3F1DD2487199874393CD4D832186800654760E1E34C09E4D155179F9EC0"
      "     DC4473F996BDCE6EED1CABED8B6F116F7AD9CF505DF0F998E34AB27514B0FFE7#)"
      " (x #69C7548C21D0DFEA6B9A51C9EAD4E27C33D3B3F180316E5BCAB92C933F0E4DBC#)"
      " (y #667098C654426C78D7F8201EAC6C203EF030D43605032C2F1FA937E5237DBD94"
      "     9F34A0A2564FE126DC8B715C5141802CE0979C8246463C40E6B6BDAA2513FA61"
      "     1728716C2E4FD53BC95B89E69949D96512E873B9C8F8DFD499CC312882561ADE"
      "     CB31F658E934C0C197F2C4D96B05CBAD67381E7B768891E4DA3843D24D94CDFB"
      "     5126E9B8BF21E8358EE0E0A30EF13FD6A664C0DCE3731F7FB49A4845A4FD8254"
      "     687972A2D382599C9BAC4E0ED7998193078913032558134976410B89D2C171D1"
      "     23AC35FD977219597AA7D15C1A9A428E59194F75C721EBCBCFAE44696A499AFA"
      "     74E04299F132026601638CB87AB79190D4A0986315DA8EEC6561C938996BEADF#)"
      " ))"
    },
    {
      "ECDSA, 192 bits (prime field)",
      "(private-key"
      " (ecdsa"
      " (curve \"NIST P-192\")"
      " (q #04AC2C77F529F91689FEA0EA5EFEC7F210D8EEA0B9E047ED56"
      "       3BC723E57670BD4887EBC732C523063D0A7C957BC97C1C43#)"
      " (d #6FAB034934E4C0FC9AE67F5B5659A9D7D1FEFD187EE09FD4#)"
      " ))"
    },
    {
      "ECDSA, 224 bits (prime field)",
      "(private-key"
      " (ecdsa"
      " (curve \"NIST P-224\")"
      " (q #04"
      "     00CF08DA5AD719E42707FA431292DEA11244D64FC51610D94B130D6C"
      "     EEAB6F3DEBE455E3DBF85416F7030CBD94F34F2D6F232C69F3C1385A#)"
      " (d #F220266E1105BFE3083E03EC7A3A654651F45E37167E88600BF257C1#)"
      " ))"
    },
    {
      "ECDSA, 256 bits (prime field)",
      "(private-key"
      " (ecdsa"
      " (curve \"NIST P-256\")"
      " (q #04"
      "     60FED4BA255A9D31C961EB74C6356D68C049B8923B61FA6CE669622E60F29FB6"
      "     7903FE1008B8BC99A41AE9E95628BC64F2F1B20C2D7E9F5177A3C294D4462299#)"
      " (d #C9AFA9D845BA75166B5C215767B1D6934E50C3DB36E89B127B8A622B120F6721#)"
      " ))"
    },
    {
      "ECDSA, 384 bits (prime field)",
      "(private-key"
      " (ecdsa"
      " (curve \"NIST P-384\")"
      " (q #04"
      "     EC3A4E415B4E19A4568618029F427FA5DA9A8BC4AE92E02E06AAE5286B300C64"
      "     DEF8F0EA9055866064A254515480BC13"
      "     8015D9B72D7D57244EA8EF9AC0C621896708A59367F9DFB9F54CA84B3F1C9DB1"
      "     288B231C3AE0D4FE7344FD2533264720#)"
      " (d #6B9D3DAD2E1B8C1C05B19875B6659F4DE23C3B667BF297BA9AA47740787137D8"
      "     96D5724E4C70A825F872C9EA60D2EDF5#)"
      " ))"
    },
    {
      "ECDSA, 521 bits (prime field)",
      "(private-key"
      " (ecdsa"
      " (curve \"NIST P-521\")"
      " (q #04"
      "     01894550D0785932E00EAA23B694F213F8C3121F86DC97A04E5A7167DB4E5BCD"
      "     371123D46E45DB6B5D5370A7F20FB633155D38FFA16D2BD761DCAC474B9A2F50"
      "     23A4"
      "     00493101C962CD4D2FDDF782285E64584139C2F91B47F87FF82354D6630F746A"
      "     28A0DB25741B5B34A828008B22ACC23F924FAAFBD4D33F81EA66956DFEAA2BFD"
      "     FCF5#)"
      " (d #FAD06DAA62BA3B25D2FB40133DA757205DE67F5BB0018FEE8C86E1B68C7E75"
      "     CAA896EB32F1F47C70855836A6D16FCC1466F6D8FBEC67DB89EC0C08B0E996B8"
      "     3538#)"
      " ))"
    },
    { NULL }
  };

  static struct {
    const char *keyname;
    const char *name;
    const char *hashname;
    const char *message;
    const char *k, *r, *s;
  } tests[] = {
    {
      "DSA, 1024 bits",
      "With SHA-1, message = \"sample\"",
      "sha1", "sample",
      "7BDB6B0FF756E1BB5D53583EF979082F9AD5BD5B",
      "2E1A0C2562B2912CAAF89186FB0F42001585DA55",
      "29EFB6B0AFF2D7A68EB70CA313022253B9A88DF5"
    },
    {
      "DSA, 1024 bits",
      "With SHA-224, message = \"sample\"",
      "sha224", "sample",
      "562097C06782D60C3037BA7BE104774344687649",
      "4BC3B686AEA70145856814A6F1BB53346F02101E",
      "410697B92295D994D21EDD2F4ADA85566F6F94C1"
    },
    {
      "DSA, 1024 bits",
      "With SHA-256, message = \"sample\"",
      "sha256", "sample",
      "519BA0546D0C39202A7D34D7DFA5E760B318BCFB",
      "81F2F5850BE5BC123C43F71A3033E9384611C545",
      "4CDD914B65EB6C66A8AAAD27299BEE6B035F5E89"
    },
    {
      "DSA, 1024 bits",
      "With SHA-384, message = \"sample\"",
      "sha384", "sample",
      "95897CD7BBB944AA932DBC579C1C09EB6FCFC595",
      "07F2108557EE0E3921BC1774F1CA9B410B4CE65A",
      "54DF70456C86FAC10FAB47C1949AB83F2C6F7595"
    },
    {
      "DSA, 1024 bits",
      "With SHA-512, message = \"sample\"",
      "sha512", "sample",
      "09ECE7CA27D0F5A4DD4E556C9DF1D21D28104F8B",
      "16C3491F9B8C3FBBDD5E7A7B667057F0D8EE8E1B",
      "02C36A127A7B89EDBB72E4FFBC71DABC7D4FC69C"
    },
    {
      "DSA, 1024 bits",
      "With SHA-1, message = \"test\"",
      "sha1", "test",
      "5C842DF4F9E344EE09F056838B42C7A17F4A6433",
      "42AB2052FD43E123F0607F115052A67DCD9C5C77",
      "183916B0230D45B9931491D4C6B0BD2FB4AAF088"
    },
    {
      "DSA, 1024 bits",
      "With SHA-224, message = \"test\"",
      "sha224", "test",
      "4598B8EFC1A53BC8AECD58D1ABBB0C0C71E67297",
      "6868E9964E36C1689F6037F91F28D5F2C30610F2",
      "49CEC3ACDC83018C5BD2674ECAAD35B8CD22940F"
    },
    {
      "DSA, 1024 bits",
      "With SHA-256, message = \"test\"",
      "sha256", "test",
      "5A67592E8128E03A417B0484410FB72C0B630E1A",
      "22518C127299B0F6FDC9872B282B9E70D0790812",
      "6837EC18F150D55DE95B5E29BE7AF5D01E4FE160"
    },
    {
      "DSA, 1024 bits",
      "With SHA-384, message = \"test\"",
      "sha384", "test",
      "220156B761F6CA5E6C9F1B9CF9C24BE25F98CD89",
      "854CF929B58D73C3CBFDC421E8D5430CD6DB5E66",
      "91D0E0F53E22F898D158380676A871A157CDA622"
    },
    {
      "DSA, 1024 bits",
      "With SHA-512, message = \"test\"",
      "sha512", "test",
      "65D2C2EEB175E370F28C75BFCDC028D22C7DBE9C",
      "8EA47E475BA8AC6F2D821DA3BD212D11A3DEB9A0",
      "7C670C7AD72B6C050C109E1790008097125433E8"
    },
    {
      "DSA, 2048 bits",
      "With SHA-1, message = \"sample\"",
      "sha1", "sample",
      "888FA6F7738A41BDC9846466ABDB8174C0338250AE50CE955CA16230F9CBD53E",
      "3A1B2DBD7489D6ED7E608FD036C83AF396E290DBD602408E8677DAABD6E7445A",
      "D26FCBA19FA3E3058FFC02CA1596CDBB6E0D20CB37B06054F7E36DED0CDBBCCF"
    },
    {
      "DSA, 2048 bits",
      "With SHA-224, message = \"sample\"",
      "sha224", "sample",
      "BC372967702082E1AA4FCE892209F71AE4AD25A6DFD869334E6F153BD0C4D806",
      "DC9F4DEADA8D8FF588E98FED0AB690FFCE858DC8C79376450EB6B76C24537E2C",
      "A65A9C3BC7BABE286B195D5DA68616DA8D47FA0097F36DD19F517327DC848CEC"
    },
    {
      "DSA, 2048 bits",
      "With SHA-256, message = \"sample\"",
      "sha256", "sample",
      "8926A27C40484216F052F4427CFD5647338B7B3939BC6573AF4333569D597C52",
      "EACE8BDBBE353C432A795D9EC556C6D021F7A03F42C36E9BC87E4AC7932CC809",
      "7081E175455F9247B812B74583E9E94F9EA79BD640DC962533B0680793A38D53"
    },
    {
      "DSA, 2048 bits",
      "With SHA-384, message = \"sample\"",
      "sha384", "sample",
      "C345D5AB3DA0A5BCB7EC8F8FB7A7E96069E03B206371EF7D83E39068EC564920",
      "B2DA945E91858834FD9BF616EBAC151EDBC4B45D27D0DD4A7F6A22739F45C00B",
      "19048B63D9FD6BCA1D9BAE3664E1BCB97F7276C306130969F63F38FA8319021B"
    },
    {
      "DSA, 2048 bits",
      "With SHA-512, message = \"sample\"",
      "sha512", "sample",
      "5A12994431785485B3F5F067221517791B85A597B7A9436995C89ED0374668FC",
      "2016ED092DC5FB669B8EFB3D1F31A91EECB199879BE0CF78F02BA062CB4C942E",
      "D0C76F84B5F091E141572A639A4FB8C230807EEA7D55C8A154A224400AFF2351"
    },
    {
      "DSA, 2048 bits",
      "With SHA-1, message = \"test\"",
      "sha1", "test",
      "6EEA486F9D41A037B2C640BC5645694FF8FF4B98D066A25F76BE641CCB24BA4F",
      "C18270A93CFC6063F57A4DFA86024F700D980E4CF4E2CB65A504397273D98EA0",
      "414F22E5F31A8B6D33295C7539C1C1BA3A6160D7D68D50AC0D3A5BEAC2884FAA"
    },
    {
      "DSA, 2048 bits",
      "With SHA-224, message = \"test\"",
      "sha224", "test",
      "06BD4C05ED74719106223BE33F2D95DA6B3B541DAD7BFBD7AC508213B6DA6670",
      "272ABA31572F6CC55E30BF616B7A265312018DD325BE031BE0CC82AA17870EA3",
      "E9CC286A52CCE201586722D36D1E917EB96A4EBDB47932F9576AC645B3A60806"
    },
    {
      "DSA, 2048 bits",
      "With SHA-256, message = \"test\"",
      "sha256", "test",
      "1D6CE6DDA1C5D37307839CD03AB0A5CBB18E60D800937D67DFB4479AAC8DEAD7",
      "8190012A1969F9957D56FCCAAD223186F423398D58EF5B3CEFD5A4146A4476F0",
      "7452A53F7075D417B4B013B278D1BB8BBD21863F5E7B1CEE679CF2188E1AB19E"
    },
    {
      "DSA, 2048 bits",
      "With SHA-384, message = \"test\"",
      "sha384", "test",
      "206E61F73DBE1B2DC8BE736B22B079E9DACD974DB00EEBBC5B64CAD39CF9F91C",
      "239E66DDBE8F8C230A3D071D601B6FFBDFB5901F94D444C6AF56F732BEB954BE",
      "6BD737513D5E72FE85D1C750E0F73921FE299B945AAD1C802F15C26A43D34961"
    },
    {
      "DSA, 2048 bits",
      "With SHA-512, message = \"test\"",
      "sha512", "test",
      "AFF1651E4CD6036D57AA8B2A05CCF1A9D5A40166340ECBBDC55BE10B568AA0AA",
      "89EC4BB1400ECCFF8E7D9AA515CD1DE7803F2DAFF09693EE7FD1353E90A68307",
      "C9F0BDABCC0D880BB137A994CC7F3980CE91CC10FAF529FC46565B15CEA854E1"
    },
    {
      "ECDSA, 192 bits (prime field)",
      "With SHA-1, message = \"sample\"",
      "sha1", "sample",
      "37D7CA00D2C7B0E5E412AC03BD44BA837FDD5B28CD3B0021",
      "98C6BD12B23EAF5E2A2045132086BE3EB8EBD62ABF6698FF",
      "57A22B07DEA9530F8DE9471B1DC6624472E8E2844BC25B64"
    },
    {
      "ECDSA, 192 bits (prime field)",
      "With SHA-224, message = \"sample\"",
      "sha224", "sample",
      "4381526B3FC1E7128F202E194505592F01D5FF4C5AF015D8",
      "A1F00DAD97AEEC91C95585F36200C65F3C01812AA60378F5",
      "E07EC1304C7C6C9DEBBE980B9692668F81D4DE7922A0F97A"
    },
    {
      "ECDSA, 192 bits (prime field)",
      "With SHA-256, message = \"sample\"",
      "sha256", "sample",
      "32B1B6D7D42A05CB449065727A84804FB1A3E34D8F261496",
      "4B0B8CE98A92866A2820E20AA6B75B56382E0F9BFD5ECB55",
      "CCDB006926EA9565CBADC840829D8C384E06DE1F1E381B85"
    },
    {
      "ECDSA, 192 bits (prime field)",
      "With SHA-384, message = \"sample\"",
      "sha384", "sample",
      "4730005C4FCB01834C063A7B6760096DBE284B8252EF4311",
      "DA63BF0B9ABCF948FBB1E9167F136145F7A20426DCC287D5",
      "C3AA2C960972BD7A2003A57E1C4C77F0578F8AE95E31EC5E"
    },
    {
      "ECDSA, 192 bits (prime field)",
      "With SHA-512, message = \"sample\"",
      "sha512", "sample",
      "A2AC7AB055E4F20692D49209544C203A7D1F2C0BFBC75DB1",
      "4D60C5AB1996BD848343B31C00850205E2EA6922DAC2E4B8",
      "3F6E837448F027A1BF4B34E796E32A811CBB4050908D8F67"
    },
    {
      "ECDSA, 192 bits (prime field)",
      "With SHA-1, message = \"test\"",
      "sha1", "test",
      "D9CF9C3D3297D3260773A1DA7418DB5537AB8DD93DE7FA25",
      "0F2141A0EBBC44D2E1AF90A50EBCFCE5E197B3B7D4DE036D",
      "EB18BC9E1F3D7387500CB99CF5F7C157070A8961E38700B7"
    },
    {
      "ECDSA, 192 bits (prime field)",
      "With SHA-224, message = \"test\"",
      "sha224", "test",
      "F5DC805F76EF851800700CCE82E7B98D8911B7D510059FBE",
      "6945A1C1D1B2206B8145548F633BB61CEF04891BAF26ED34",
      "B7FB7FDFC339C0B9BD61A9F5A8EAF9BE58FC5CBA2CB15293"
    },
    {
      "ECDSA, 192 bits (prime field)",
      "With SHA-256, message = \"test\"",
      "sha256", "test",
      "5C4CE89CF56D9E7C77C8585339B006B97B5F0680B4306C6C",
      "3A718BD8B4926C3B52EE6BBE67EF79B18CB6EB62B1AD97AE",
      "5662E6848A4A19B1F1AE2F72ACD4B8BBE50F1EAC65D9124F"
    },
    {
      "ECDSA, 192 bits (prime field)",
      "With SHA-384, message = \"test\"",
      "sha384", "test",
      "5AFEFB5D3393261B828DB6C91FBC68C230727B030C975693",
      "B234B60B4DB75A733E19280A7A6034BD6B1EE88AF5332367",
      "7994090B2D59BB782BE57E74A44C9A1C700413F8ABEFE77A"
    },
    {
      "ECDSA, 192 bits (prime field)",
      "With SHA-512, message = \"test\"",
      "sha512", "test",
      "0758753A5254759C7CFBAD2E2D9B0792EEE44136C9480527",
      "FE4F4AE86A58B6507946715934FE2D8FF9D95B6B098FE739",
      "74CF5605C98FBA0E1EF34D4B5A1577A7DCF59457CAE52290"
    },



    {
      "ECDSA, 224 bits (prime field)",
      "With SHA-1, message = \"sample\"",
      "sha1", "sample",
      "7EEFADD91110D8DE6C2C470831387C50D3357F7F4D477054B8B426BC",
      "22226F9D40A96E19C4A301CE5B74B115303C0F3A4FD30FC257FB57AC",
      "66D1CDD83E3AF75605DD6E2FEFF196D30AA7ED7A2EDF7AF475403D69"
    },
    {
      "ECDSA, 224 bits (prime field)",
      "With SHA-224, message = \"sample\"",
      "sha224", "sample",
      "C1D1F2F10881088301880506805FEB4825FE09ACB6816C36991AA06D",
      "1CDFE6662DDE1E4A1EC4CDEDF6A1F5A2FB7FBD9145C12113E6ABFD3E",
      "A6694FD7718A21053F225D3F46197CA699D45006C06F871808F43EBC"
    },
    {
      "ECDSA, 224 bits (prime field)",
      "With SHA-256, message = \"sample\"",
      "sha256", "sample",
      "AD3029E0278F80643DE33917CE6908C70A8FF50A411F06E41DEDFCDC",
      "61AA3DA010E8E8406C656BC477A7A7189895E7E840CDFE8FF42307BA",
      "BC814050DAB5D23770879494F9E0A680DC1AF7161991BDE692B10101"
    },
    {
      "ECDSA, 224 bits (prime field)",
      "With SHA-384, message = \"sample\"",
      "sha384", "sample",
      "52B40F5A9D3D13040F494E83D3906C6079F29981035C7BD51E5CAC40",
      "0B115E5E36F0F9EC81F1325A5952878D745E19D7BB3EABFABA77E953",
      "830F34CCDFE826CCFDC81EB4129772E20E122348A2BBD889A1B1AF1D"
    },
    {
      "ECDSA, 224 bits (prime field)",
      "With SHA-512, message = \"sample\"",
      "sha512", "sample",
      "9DB103FFEDEDF9CFDBA05184F925400C1653B8501BAB89CEA0FBEC14",
      "074BD1D979D5F32BF958DDC61E4FB4872ADCAFEB2256497CDAC30397",
      "A4CECA196C3D5A1FF31027B33185DC8EE43F288B21AB342E5D8EB084"
    },
    {
      "ECDSA, 224 bits (prime field)",
      "With SHA-1, message = \"test\"",
      "sha1", "test",
      "2519178F82C3F0E4F87ED5883A4E114E5B7A6E374043D8EFD329C253",
      "DEAA646EC2AF2EA8AD53ED66B2E2DDAA49A12EFD8356561451F3E21C",
      "95987796F6CF2062AB8135271DE56AE55366C045F6D9593F53787BD2"
    },
    {
      "ECDSA, 224 bits (prime field)",
      "With SHA-224, message = \"test\"",
      "sha224", "test",
      "DF8B38D40DCA3E077D0AC520BF56B6D565134D9B5F2EAE0D34900524",
      "C441CE8E261DED634E4CF84910E4C5D1D22C5CF3B732BB204DBEF019",
      "902F42847A63BDC5F6046ADA114953120F99442D76510150F372A3F4"
    },
    {
      "ECDSA, 224 bits (prime field)",
      "With SHA-256, message = \"test\"",
      "sha256", "test",
      "FF86F57924DA248D6E44E8154EB69F0AE2AEBAEE9931D0B5A969F904",
      "AD04DDE87B84747A243A631EA47A1BA6D1FAA059149AD2440DE6FBA6",
      "178D49B1AE90E3D8B629BE3DB5683915F4E8C99FDF6E666CF37ADCFD"
    },
    {
      "ECDSA, 224 bits (prime field)",
      "With SHA-384, message = \"test\"",
      "sha384", "test",
      "7046742B839478C1B5BD31DB2E862AD868E1A45C863585B5F22BDC2D",
      "389B92682E399B26518A95506B52C03BC9379A9DADF3391A21FB0EA4",
      "414A718ED3249FF6DBC5B50C27F71F01F070944DA22AB1F78F559AAB"
    },
    {
      "ECDSA, 224 bits (prime field)",
      "With SHA-512, message = \"test\"",
      "sha512", "test",
      "E39C2AA4EA6BE2306C72126D40ED77BF9739BB4D6EF2BBB1DCB6169D",
      "049F050477C5ADD858CAC56208394B5A55BAEBBE887FDF765047C17C",
      "077EB13E7005929CEFA3CD0403C7CDCC077ADF4E44F3C41B2F60ECFF"
    },
    {
      "ECDSA, 256 bits (prime field)",
      "With SHA-1, message = \"sample\"",
      "sha1", "sample",
      "882905F1227FD620FBF2ABF21244F0BA83D0DC3A9103DBBEE43A1FB858109DB4",
      "61340C88C3AAEBEB4F6D667F672CA9759A6CCAA9FA8811313039EE4A35471D32",
      "6D7F147DAC089441BB2E2FE8F7A3FA264B9C475098FDCF6E00D7C996E1B8B7EB"
    },
    {
      "ECDSA, 256 bits (prime field)",
      "With SHA-224, message = \"sample\"",
      "sha224", "sample",
      "103F90EE9DC52E5E7FB5132B7033C63066D194321491862059967C715985D473",
      "53B2FFF5D1752B2C689DF257C04C40A587FABABB3F6FC2702F1343AF7CA9AA3F",
      "B9AFB64FDC03DC1A131C7D2386D11E349F070AA432A4ACC918BEA988BF75C74C"
    },
    {
      "ECDSA, 256 bits (prime field)",
      "With SHA-256, message = \"sample\"",
      "sha256", "sample",
      "A6E3C57DD01ABE90086538398355DD4C3B17AA873382B0F24D6129493D8AAD60",
      "EFD48B2AACB6A8FD1140DD9CD45E81D69D2C877B56AAF991C34D0EA84EAF3716",
      "F7CB1C942D657C41D436C7A1B6E29F65F3E900DBB9AFF4064DC4AB2F843ACDA8"
    },
    {
      "ECDSA, 256 bits (prime field)",
      "With SHA-384, message = \"sample\"",
      "sha384", "sample",
      "09F634B188CEFD98E7EC88B1AA9852D734D0BC272F7D2A47DECC6EBEB375AAD4",
      "0EAFEA039B20E9B42309FB1D89E213057CBF973DC0CFC8F129EDDDC800EF7719",
      "4861F0491E6998B9455193E34E7B0D284DDD7149A74B95B9261F13ABDE940954"
    },
    {
      "ECDSA, 256 bits (prime field)",
      "With SHA-512, message = \"sample\"",
      "sha512", "sample",
      "5FA81C63109BADB88C1F367B47DA606DA28CAD69AA22C4FE6AD7DF73A7173AA5",
      "8496A60B5E9B47C825488827E0495B0E3FA109EC4568FD3F8D1097678EB97F00",
      "2362AB1ADBE2B8ADF9CB9EDAB740EA6049C028114F2460F96554F61FAE3302FE"
    },
    {
      "ECDSA, 256 bits (prime field)",
      "With SHA-1, message = \"test\"",
      "sha1", "test",
      "8C9520267C55D6B980DF741E56B4ADEE114D84FBFA2E62137954164028632A2E",
      "0CBCC86FD6ABD1D99E703E1EC50069EE5C0B4BA4B9AC60E409E8EC5910D81A89",
      "01B9D7B73DFAA60D5651EC4591A0136F87653E0FD780C3B1BC872FFDEAE479B1"
    },
    {
      "ECDSA, 256 bits (prime field)",
      "With SHA-224, message = \"test\"",
      "sha224", "test",
      "669F4426F2688B8BE0DB3A6BD1989BDAEFFF84B649EEB84F3DD26080F667FAA7",
      "C37EDB6F0AE79D47C3C27E962FA269BB4F441770357E114EE511F662EC34A692",
      "C820053A05791E521FCAAD6042D40AEA1D6B1A540138558F47D0719800E18F2D"
    },
    {
      "ECDSA, 256 bits (prime field)",
      "With SHA-256, message = \"test\"",
      "sha256", "test",
      "D16B6AE827F17175E040871A1C7EC3500192C4C92677336EC2537ACAEE0008E0",
      "F1ABB023518351CD71D881567B1EA663ED3EFCF6C5132B354F28D3B0B7D38367",
      "019F4113742A2B14BD25926B49C649155F267E60D3814B4C0CC84250E46F0083"
    },
    {
      "ECDSA, 256 bits (prime field)",
      "With SHA-384, message = \"test\"",
      "sha384", "test",
      "16AEFFA357260B04B1DD199693960740066C1A8F3E8EDD79070AA914D361B3B8",
      "83910E8B48BB0C74244EBDF7F07A1C5413D61472BD941EF3920E623FBCCEBEB6",
      "8DDBEC54CF8CD5874883841D712142A56A8D0F218F5003CB0296B6B509619F2C"
    },
    {
      "ECDSA, 256 bits (prime field)",
      "With SHA-512, message = \"test\"",
      "sha512", "test",
      "6915D11632ACA3C40D5D51C08DAF9C555933819548784480E93499000D9F0B7F",
      "461D93F31B6540894788FD206C07CFA0CC35F46FA3C91816FFF1040AD1581A04",
      "39AF9F15DE0DB8D97E72719C74820D304CE5226E32DEDAE67519E840D1194E55"
    },
    {
      "ECDSA, 384 bits (prime field)",
      "With SHA-1, message = \"sample\"",
      "sha1", "sample",
      "4471EF7518BB2C7C20F62EAE1C387AD0C5E8E470995DB4ACF694466E6AB09663"
      "0F29E5938D25106C3C340045A2DB01A7",
      "EC748D839243D6FBEF4FC5C4859A7DFFD7F3ABDDF72014540C16D73309834FA3"
      "7B9BA002899F6FDA3A4A9386790D4EB2",
      "A3BCFA947BEEF4732BF247AC17F71676CB31A847B9FF0CBC9C9ED4C1A5B3FACF"
      "26F49CA031D4857570CCB5CA4424A443"
    },
    {
      "ECDSA, 384 bits (prime field)",
      "With SHA-224, message = \"sample\"",
      "sha224", "sample",
      "A4E4D2F0E729EB786B31FC20AD5D849E304450E0AE8E3E341134A5C1AFA03CAB"
      "8083EE4E3C45B06A5899EA56C51B5879",
      "42356E76B55A6D9B4631C865445DBE54E056D3B3431766D0509244793C3F9366"
      "450F76EE3DE43F5A125333A6BE060122",
      "9DA0C81787064021E78DF658F2FBB0B042BF304665DB721F077A4298B095E483"
      "4C082C03D83028EFBF93A3C23940CA8D"
    },
    {
      "ECDSA, 384 bits (prime field)",
      "With SHA-256, message = \"sample\"",
      "sha256", "sample",
      "180AE9F9AEC5438A44BC159A1FCB277C7BE54FA20E7CF404B490650A8ACC414E"
      "375572342863C899F9F2EDF9747A9B60",
      "21B13D1E013C7FA1392D03C5F99AF8B30C570C6F98D4EA8E354B63A21D3DAA33"
      "BDE1E888E63355D92FA2B3C36D8FB2CD",
      "F3AA443FB107745BF4BD77CB3891674632068A10CA67E3D45DB2266FA7D1FEEB"
      "EFDC63ECCD1AC42EC0CB8668A4FA0AB0"
    },
    {
      "ECDSA, 384 bits (prime field)",
      "With SHA-384, message = \"sample\"",
      "sha384", "sample",
      "94ED910D1A099DAD3254E9242AE85ABDE4BA15168EAF0CA87A555FD56D10FBCA"
      "2907E3E83BA95368623B8C4686915CF9",
      "94EDBB92A5ECB8AAD4736E56C691916B3F88140666CE9FA73D64C4EA95AD133C"
      "81A648152E44ACF96E36DD1E80FABE46",
      "99EF4AEB15F178CEA1FE40DB2603138F130E740A19624526203B6351D0A3A94F"
      "A329C145786E679E7B82C71A38628AC8"
    },
    {
      "ECDSA, 384 bits (prime field)",
      "With SHA-512, message = \"sample\"",
      "sha512", "sample",
      "92FC3C7183A883E24216D1141F1A8976C5B0DD797DFA597E3D7B32198BD35331"
      "A4E966532593A52980D0E3AAA5E10EC3",
      "ED0959D5880AB2D869AE7F6C2915C6D60F96507F9CB3E047C0046861DA4A799C"
      "FE30F35CC900056D7C99CD7882433709",
      "512C8CCEEE3890A84058CE1E22DBC2198F42323CE8ACA9135329F03C068E5112"
      "DC7CC3EF3446DEFCEB01A45C2667FDD5"
    },
    {
      "ECDSA, 384 bits (prime field)",
      "With SHA-1, message = \"test\"",
      "sha1", "test",
      "66CC2C8F4D303FC962E5FF6A27BD79F84EC812DDAE58CF5243B64A4AD8094D47"
      "EC3727F3A3C186C15054492E30698497",
      "4BC35D3A50EF4E30576F58CD96CE6BF638025EE624004A1F7789A8B8E43D0678"
      "ACD9D29876DAF46638645F7F404B11C7",
      "D5A6326C494ED3FF614703878961C0FDE7B2C278F9A65FD8C4B7186201A29916"
      "95BA1C84541327E966FA7B50F7382282"
    },
    {
      "ECDSA, 384 bits (prime field)",
      "With SHA-224, message = \"test\"",
      "sha224", "test",
      "18FA39DB95AA5F561F30FA3591DC59C0FA3653A80DAFFA0B48D1A4C6DFCBFF6E"
      "3D33BE4DC5EB8886A8ECD093F2935726",
      "E8C9D0B6EA72A0E7837FEA1D14A1A9557F29FAA45D3E7EE888FC5BF954B5E624"
      "64A9A817C47FF78B8C11066B24080E72",
      "07041D4A7A0379AC7232FF72E6F77B6DDB8F09B16CCE0EC3286B2BD43FA8C614"
      "1C53EA5ABEF0D8231077A04540A96B66"
    },
    {
      "ECDSA, 384 bits (prime field)",
      "With SHA-256, message = \"test\"",
      "sha256", "test",
      "0CFAC37587532347DC3389FDC98286BBA8C73807285B184C83E62E26C401C0FA"
      "A48DD070BA79921A3457ABFF2D630AD7",
      "6D6DEFAC9AB64DABAFE36C6BF510352A4CC27001263638E5B16D9BB51D451559"
      "F918EEDAF2293BE5B475CC8F0188636B",
      "2D46F3BECBCC523D5F1A1256BF0C9B024D879BA9E838144C8BA6BAEB4B53B47D"
      "51AB373F9845C0514EEFB14024787265"
    },
    {
      "ECDSA, 384 bits (prime field)",
      "With SHA-384, message = \"test\"",
      "sha384", "test",
      "015EE46A5BF88773ED9123A5AB0807962D193719503C527B031B4C2D225092AD"
      "A71F4A459BC0DA98ADB95837DB8312EA",
      "8203B63D3C853E8D77227FB377BCF7B7B772E97892A80F36AB775D509D7A5FEB"
      "0542A7F0812998DA8F1DD3CA3CF023DB",
      "DDD0760448D42D8A43AF45AF836FCE4DE8BE06B485E9B61B827C2F13173923E0"
      "6A739F040649A667BF3B828246BAA5A5"
    },
    {
      "ECDSA, 384 bits (prime field)",
      "With SHA-512, message = \"test\"",
      "sha512", "test",
      "3780C4F67CB15518B6ACAE34C9F83568D2E12E47DEAB6C50A4E4EE5319D1E8CE"
      "0E2CC8A136036DC4B9C00E6888F66B6C",
      "A0D5D090C9980FAF3C2CE57B7AE951D31977DD11C775D314AF55F76C676447D0"
      "6FB6495CD21B4B6E340FC236584FB277",
      "976984E59B4C77B0E8E4460DCA3D9F20E07B9BB1F63BEEFAF576F6B2E8B22463"
      "4A2092CD3792E0159AD9CEE37659C736"
    },
    {
      "ECDSA, 521 bits (prime field)",
      "With SHA-1, message = \"sample\"",
      "sha1", "sample",
      "0089C071B419E1C2820962321787258469511958E80582E95D8378E0C2CCDB3CB"
      "42BEDE42F50E3FA3C71F5A76724281D31D9C89F0F91FC1BE4918DB1C03A5838D"
      "0F9",
      "343B6EC45728975EA5CBA6659BBB6062A5FF89EEA58BE3C80B619F322C87910"
      "FE092F7D45BB0F8EEE01ED3F20BABEC079D202AE677B243AB40B5431D497C55D"
      "75D",
      "E7B0E675A9B24413D448B8CC119D2BF7B2D2DF032741C096634D6D65D0DBE3D"
      "5694625FB9E8104D3B842C1B0E2D0B98BEA19341E8676AEF66AE4EBA3D5475D5"
      "D16"
    },
    {
      "ECDSA, 521 bits (prime field)",
      "With SHA-224, message = \"sample\"",
      "sha224", "sample",
      "121415EC2CD7726330A61F7F3FA5DE14BE9436019C4DB8CB4041F3B54CF31BE0"
      "493EE3F427FB906393D895A19C9523F3A1D54BB8702BD4AA9C99DAB2597B9211"
      "3F3",
      "01776331CFCDF927D666E032E00CF776187BC9FDD8E69D0DABB4109FFE1B5E2A3"
      "0715F4CC923A4A5E94D2503E9ACFED92857B7F31D7152E0F8C00C15FF3D87E2E"
      "D2E",
      "50CB5265417FE2320BBB5A122B8E1A32BD699089851128E360E620A30C7E17B"
      "A41A666AF126CE100E5799B153B60528D5300D08489CA9178FB610A2006C254B"
      "41F"
    },
    {
      "ECDSA, 521 bits (prime field)",
      "With SHA-256, message = \"sample\"",
      "sha256", "sample",
      "0EDF38AFCAAECAB4383358B34D67C9F2216C8382AAEA44A3DAD5FDC9C3257576"
      "1793FEF24EB0FC276DFC4F6E3EC476752F043CF01415387470BCBD8678ED2C7E"
      "1A0",
      "01511BB4D675114FE266FC4372B87682BAECC01D3CC62CF2303C92B3526012659"
      "D16876E25C7C1E57648F23B73564D67F61C6F14D527D54972810421E7D87589E"
      "1A7",
      "4A171143A83163D6DF460AAF61522695F207A58B95C0644D87E52AA1A347916"
      "E4F7A72930B1BC06DBE22CE3F58264AFD23704CBB63B29B931F7DE6C9D949A7E"
      "CFC"
    },
    {
      "ECDSA, 521 bits (prime field)",
      "With SHA-384, message = \"sample\"",
      "sha384", "sample",
      "1546A108BC23A15D6F21872F7DED661FA8431DDBD922D0DCDB77CC878C8553FF"
      "AD064C95A920A750AC9137E527390D2D92F153E66196966EA554D9ADFCB109C4"
      "211",
      "01EA842A0E17D2DE4F92C15315C63DDF72685C18195C2BB95E572B9C5136CA4B4"
      "B576AD712A52BE9730627D16054BA40CC0B8D3FF035B12AE75168397F5D50C67"
      "451",
      "01F21A3CEE066E1961025FB048BD5FE2B7924D0CD797BABE0A83B66F1E35EEAF5"
      "FDE143FA85DC394A7DEE766523393784484BDF3E00114A1C857CDE1AA203DB65"
      "D61"
    },
    {
      "ECDSA, 521 bits (prime field)",
      "With SHA-512, message = \"sample\"",
      "sha512", "sample",
      "1DAE2EA071F8110DC26882D4D5EAE0621A3256FC8847FB9022E2B7D28E6F1019"
      "8B1574FDD03A9053C08A1854A168AA5A57470EC97DD5CE090124EF52A2F7ECBF"
      "FD3",
      "C328FAFCBD79DD77850370C46325D987CB525569FB63C5D3BC53950E6D4C5F1"
      "74E25A1EE9017B5D450606ADD152B534931D7D4E8455CC91F9B15BF05EC36E37"
      "7FA",
      "617CCE7CF5064806C467F678D3B4080D6F1CC50AF26CA209417308281B68AF2"
      "82623EAA63E5B5C0723D8B8C37FF0777B1A20F8CCB1DCCC43997F1EE0E44DA4A"
      "67A"
    },
    {
      "ECDSA, 521 bits (prime field)",
      "With SHA-1, message = \"test\"",
      "sha1", "test",
      "0BB9F2BF4FE1038CCF4DABD7139A56F6FD8BB1386561BD3C6A4FC818B20DF5DD"
      "BA80795A947107A1AB9D12DAA615B1ADE4F7A9DC05E8E6311150F47F5C57CE8B"
      "222",
      "013BAD9F29ABE20DE37EBEB823C252CA0F63361284015A3BF430A46AAA80B87B0"
      "693F0694BD88AFE4E661FC33B094CD3B7963BED5A727ED8BD6A3A202ABE009D0"
      "367",
      "01E9BB81FF7944CA409AD138DBBEE228E1AFCC0C890FC78EC8604639CB0DBDC90"
      "F717A99EAD9D272855D00162EE9527567DD6A92CBD629805C0445282BBC91679"
      "7FF"
    },
    {
      "ECDSA, 521 bits (prime field)",
      "With SHA-224, message = \"test\"",
      "sha224", "test",
      "040D09FCF3C8A5F62CF4FB223CBBB2B9937F6B0577C27020A99602C25A011369"
      "87E452988781484EDBBCF1C47E554E7FC901BC3085E5206D9F619CFF07E73D6F"
      "706",
      "01C7ED902E123E6815546065A2C4AF977B22AA8EADDB68B2C1110E7EA44D42086"
      "BFE4A34B67DDC0E17E96536E358219B23A706C6A6E16BA77B65E1C595D43CAE1"
      "7FB",
      "0177336676304FCB343CE028B38E7B4FBA76C1C1B277DA18CAD2A8478B2A9A9F5"
      "BEC0F3BA04F35DB3E4263569EC6AADE8C92746E4C82F8299AE1B8F1739F8FD51"
      "9A4"
    },
    {
      "ECDSA, 521 bits (prime field)",
      "With SHA-256, message = \"test\"",
      "sha256", "test",
      "01DE74955EFAABC4C4F17F8E84D881D1310B5392D7700275F82F145C61E84384"
      "1AF09035BF7A6210F5A431A6A9E81C9323354A9E69135D44EBD2FCAA7731B909"
      "258",
      "0E871C4A14F993C6C7369501900C4BC1E9C7B0B4BA44E04868B30B41D807104"
      "2EB28C4C250411D0CE08CD197E4188EA4876F279F90B3D8D74A3C76E6F1E4656"
      "AA8",
      "CD52DBAA33B063C3A6CD8058A1FB0A46A4754B034FCC644766CA14DA8CA5CA9"
      "FDE00E88C1AD60CCBA759025299079D7A427EC3CC5B619BFBC828E7769BCD694"
      "E86"
    },
    {
      "ECDSA, 521 bits (prime field)",
      "With SHA-384, message = \"test\"",
      "sha384", "test",
      "1F1FC4A349A7DA9A9E116BFDD055DC08E78252FF8E23AC276AC88B1770AE0B5D"
      "CEB1ED14A4916B769A523CE1E90BA22846AF11DF8B300C38818F713DADD85DE0"
      "C88",
      "014BEE21A18B6D8B3C93FAB08D43E739707953244FDBE924FA926D76669E7AC8C"
      "89DF62ED8975C2D8397A65A49DCC09F6B0AC62272741924D479354D74FF60755"
      "78C",
      "0133330865C067A0EAF72362A65E2D7BC4E461E8C8995C3B6226A21BD1AA78F0E"
      "D94FE536A0DCA35534F0CD1510C41525D163FE9D74D134881E35141ED5E8E95B"
      "979"
    },
    {
      "ECDSA, 521 bits (prime field)",
      "With SHA-512, message = \"test\"",
      "sha512", "test",
      "16200813020EC986863BEDFC1B121F605C1215645018AEA1A7B215A564DE9EB1"
      "B38A67AA1128B80CE391C4FB71187654AAA3431027BFC7F395766CA988C964DC"
      "56D",
      "013E99020ABF5CEE7525D16B69B229652AB6BDF2AFFCAEF38773B4B7D08725F10"
      "CDB93482FDCC54EDCEE91ECA4166B2A7C6265EF0CE2BD7051B7CEF945BABD47E"
      "E6D",
      "01FBD0013C674AA79CB39849527916CE301C66EA7CE8B80682786AD60F98F7E78"
      "A19CA69EFF5C57400E3B3A0AD66CE0978214D13BAF4E9AC60752F7B155E2DE4D"
      "CE3"
    },
    { NULL }
  };

  gpg_error_t err;
  int tno, i, hashalgo;
  gcry_sexp_t seckey, data, sig;
  unsigned char digest[64];
  int digestlen;

  for (tno = 0; tests[tno].keyname; tno++)
    {
      if (verbose)
        info ("Test %d: %s. %s.\n", tno, tests[tno].keyname, tests[tno].name);

      {
        for (i=0; keys[i].name; i++)
          if (!strcmp (tests[tno].keyname, keys[i].name))
            break;
        if (!keys[i].name)
          die ("Key '%s' used by test '%s' not found\n",
               tests[tno].keyname, tests[tno].name);

        err = gcry_sexp_new (&seckey, keys[i].key, 0, 1);
        if (err)
          die ("reading key failed: %s\n", gpg_strerror (err));
      }

      hashalgo = gcry_md_map_name (tests[tno].hashname);
      if (!hashalgo)
        die ("hash with name '%s' is not supported\n", tests[tno].hashname);

      digestlen = gcry_md_get_algo_dlen (hashalgo);
      if (digestlen > sizeof digest)
        die ("internal error: digest does not fit into our buffer\n");

      gcry_md_hash_buffer (hashalgo, digest,
                           tests[tno].message, strlen (tests[tno].message));

      err = gcry_sexp_build (&data, NULL,
                             "(data "
                             " (flags rfc6979)"
                             " (hash %s %b))",
                             tests[tno].hashname, digestlen, digest);
      if (err)
        die ("building data sexp failed: %s\n", gpg_strerror (err));

      err = gcry_pk_sign (&sig, data, seckey);
      if (err)
        fail ("signing failed: %s\n", gpg_strerror (err));

      extract_cmp_data (sig, "r", tests[tno].r);
      extract_cmp_data (sig, "s", tests[tno].s);

      err = gcry_pk_verify (sig, data, seckey);
      if (err)
        fail ("verification failed: %s\n", gpg_strerror (err));

      gcry_sexp_release (sig);
      gcry_sexp_release (data);
      gcry_sexp_release (seckey);
    }
}



int
main (int argc, char **argv)
{
  int debug = 0;

  if (argc > 1 && !strcmp (argv[1], "--verbose"))
    verbose = 1;
  else if (argc > 1 && !strcmp (argv[1], "--debug"))
    {
      verbose = 2;
      debug = 1;
    }

  gcry_control (GCRYCTL_DISABLE_SECMEM, 0);
  /* Check that we test exactly our version - including the patchlevel.  */
  if (strcmp (GCRYPT_VERSION, gcry_check_version (NULL)))
    die ("version mismatch; pgm=%s, library=%s\n",
         GCRYPT_VERSION,gcry_check_version (NULL));
  gcry_control (GCRYCTL_INITIALIZATION_FINISHED, 0);
  if (debug)
    gcry_control (GCRYCTL_SET_DEBUG_FLAGS, 1u, 0);
  /* No valuable keys are create, so we can speed up our RNG. */
  gcry_control (GCRYCTL_ENABLE_QUICK_RANDOM, 0);

  check_dsa_rfc6979 ();

  return error_count ? 1 : 0;
}
