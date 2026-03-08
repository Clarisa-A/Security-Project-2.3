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

}
