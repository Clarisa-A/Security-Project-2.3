#include "DES.h"
#include <string>
#include <vector>

using namespace std;

string CBC_encryption(vector<string> blocks, string key, string IV) {
  vector<string> keys = key_gen(key);
  string prev = IV; 
  string ciphertext = "";

  for(int i = 0; i < blocks.size(); ++i){
	 string mixed = XOR(blocks[i], prev, 64);
	 string c = encryption(mixed, keys);
	 ciphertext += c;
	 prev = c;
  }
  return ciphertext;
}

string CBC_decryption(vector<string> blocks, string key, string IV) {

  // generate DES round keys/initalize with IV
  vector<string> keys = key_gen(key);
  string prev = IV;
  string plaintext = "";

  // DES decryption
  for(int i = 0; i < blocks.size(); ++i){
    string decrypted = decryption(blocks[i], keys);
    // XOR with previous ciphertext/IV
    string original = XOR(decrypted, prev, 64);
    // append plaintext
    plaintext += original;
    // update previous block
    prev = blocks[i];
  }

  return plaintext;

}
