#include <iostream>
using namespace std;
#include <cstring> //for handleing string
#include<sstream>//for handleing string
string uppercase (string letter){
  /*This fuction takes a string an check every alphabet.
  if the alphabet is lowercased it convert it into uppercase*/
    string uppercased = "";
    for (int i = 0; i < (letter.size()); i++) {
        if (letter[i] >= 97 && letter[i] <= 122){
          uppercased += letter[i]-32;
        }
        else{
          uppercased += letter[i];
        }
    }
    return uppercased;
}
string cleaner(string sentence) {
  /*This fuction checks if there is any non alphabet element it removes it*/
  string cleaned = "";
  for (int i = 0; i < sentence.size(); i++) {
    if (sentence[i] >= 65 && sentence[i] <= 90 || sentence[i] >= 97 && sentence[i] <= 122 ) {
      cleaned += sentence[i];
    }
}
  for (int j = 0; j < cleaned.size(); j++) {
    if (cleaned[j] == 106) {
      cleaned[j] = 73;
  }
}
std::cout << "cleaned "<<cleaned << '\n';
return cleaned;
}

string remove_repetition(string word){
  string rep_removed ;
  bool flag = true;
  rep_removed = word[0];
  int j,i;
for (i = 1; i < word.size(); i++) {
  flag = true;
  for (j = 0; j < rep_removed.size(); j++) {
    if (word[i] == rep_removed[j] ) {
      flag = false;
    }

  }
    if(flag == true){
      rep_removed += word[i];
    }
  }
  return rep_removed;
}
void matrix_input(string matrix[5][5], string key, string text){
  string encrypted = "";
  int count = 0;
  int count_text = 0;
  int count_len = 0;
  int index_j, index_k;
  int index_m, index_n;
  // std::cout << "key = " <<key<< '\n';
  std::cout << "text = " <<text<< '\n';
  //matrix is made
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        matrix[i][j] = key[count];
        count++;
        }
      }
//matrix is printed
    for (int a = 0; a < 5; a++) {
      for (int b = 0; b < 5; b++) {
        std::cout <<matrix[a][b];
      }
      std::cout << '\n';
    }
//encryption started//
for (int z = 0; z < text.size()/2; z++) {


    for (int j = 0; j < 5; j++) {
        string s;
        stringstream ss;
        ss<< text[count_text];
        ss>> s;
        for (int k = 0; k < 5; k++) {
        if (matrix[j][k] == s) {
          index_j = j;
          index_k = k;
          count_len ++;
          break;
        }
      }
      string d;
      stringstream aa;
      aa<< text[count_text+1];
      aa>> d;
      for (int k = 0; k < 5; k++) {
      if (matrix[j][k] == d) {
        index_m = j;
        index_n = k;
        count_len++;
        break;
      }
      }
    }
    if (index_k == index_n) {
      int indx_j, indx_m;
      indx_j = index_j + 1;
      indx_m = index_m + 1;
      if (indx_j > 4) {
        indx_j = 0;
      }
      if (indx_m > 4) {
        indx_m = 0;
      }
      encrypted += matrix[indx_j][index_k];
      encrypted += matrix[indx_m][index_n];
      count_text = count_len;
      // std::cout << "encrypted " <<encrypted<< '\n';
      index_j = 0;
      index_k = 0;
      index_m = 0;
      index_n = 0;
    }

  else if (index_j == index_m) {
    int indx_k, indx_n;
    indx_k = index_k + 1;
    indx_n = index_n + 1;
    if (indx_k > 4) {
      indx_k = 0;
    }
    if (indx_n > 4) {
      indx_n = 0;
    }
    encrypted += matrix[index_j][indx_k];
    encrypted += matrix[index_m][indx_n];
    count_text = count_len;
    // std::cout << "encrypted " <<encrypted<< '\n';
    index_j = 0;
    index_k = 0;
    index_m = 0;
    index_n = 0;
  }
  else{
    encrypted += matrix[index_m][index_k];
    encrypted += matrix[index_j][index_n];
    count_text = count_len;
    index_j = 0;
    index_k = 0;
    index_m = 0;
    index_n = 0;
  }

  }
  std::cout << "encrypted " <<encrypted<< '\n';
    }

int main(int argc, char const *argv[]) {
  string key, repitation_removed_key,key_final;
  string matrix[5][5];

  std::cout << "please enter text you want to encrypt" << '\n';
    string text, final_text;
    getline(std::cin, text);
    std::cout << "text = "<< text << '\n';

    string cleaned_text = cleaner(text);
    // std::cout << "cleaned_text = "<<cleaned_text << '\n';

    string uppercased_text = uppercase(cleaned_text);
    // std::cout << "uppercased_text = " << uppercased_text<< '\n';
    for (size_t j = 0; j < uppercased_text.size(); j++) {
      if(uppercased_text[j] == uppercased_text[j+1]){
        final_text += uppercased_text[j];
        final_text += "X";
      }
      else{
        final_text += uppercased_text[j];
      }
    }

    if (uppercased_text.size()%2 != 0) {
      uppercased_text += "Y";
      std::cout << "uppercased_text 'Y' added: "<<uppercased_text << '\n';
    }
    std::cout << "please enter secret key" << '\n';
    std::cin >> key;
    repitation_removed_key = remove_repetition(key);
    string uppercased_key = uppercase(repitation_removed_key);
    uppercased_key += "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    key_final = remove_repetition(uppercased_key);
    // std::cout << "repitation_removed "<<key_final << '\n';


     matrix_input(matrix,key_final,final_text);
return 0;
}
