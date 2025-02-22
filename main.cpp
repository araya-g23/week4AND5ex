#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <random>
using namespace std;

void question1();
void question2();
void question3();
void question4();
void question6();
void question7();
void question8();
void question9();

int main() {
 // question1();
  //question2();
  //question3();
  //question4();
  //question6();
  //question7();
  //question8();
  question9();



}
void display(const vector<int> &number,string message="vector contents") {//modified for question 6 "string message"
cout << message << "{";
  vector<int>::const_iterator it;
  for (it = number.cbegin(); it != number.cend(); it++) {
    if (it!=number.cbegin()) {
      cout << ", ";
    }
    cout << *it;

  }
  cout << "}" << endl;

}
void readFile(string fileName ,vector<int> &numbers) {
  ifstream fin(fileName);
  if (fin) {
    int num;
    while (!fin.eof()) {
      fin >> num;
      numbers.push_back(num);
    }
    fin.close();
  }
  else {
    cout << "File could not be opened" << endl;
    system("exit");
  }

}
void question1() {
  vector<int> numbers;
  string fileName="number.txt";
  readFile(fileName,numbers);
  display(numbers);
  auto func=[](int x,int y){return x>y;};
  sort(numbers.begin(),numbers.end(),func);
  display(numbers);

}
void displayQ2(const list<int> &myList) {
  list<int>::const_iterator it=myList.begin();
  while (it!=myList.end()) {
    cout<<" "<<*it;
    it++;
  }
}
//list of structure
void question2() {
  list<int>myList={1,2,3,4,5,6,};
  displayQ2(myList);
}
void question3() {
  vector<int> numbers;
  string fileName="number.txt";
  readFile(fileName,numbers);
  display(numbers);
  sort(numbers.begin(),numbers.end());
  display(numbers);
  auto func=[](int x,int y){return x>y;};
  sort(numbers.begin(),numbers.end(),func);
  display(numbers);
  auto shuff=default_random_engine {};
  shuffle(numbers.begin(),numbers.end(),shuff);
  display(numbers);
  // random_shuffle(numbers.begin(),numbers.end());
  // display(numbers);

}
void question4() {
  vector<string>words={"this","is","not","a","test"};
  auto func=[](string x,string y){return x.length()>y.length();};
  sort(words.begin(),words.end(),func);
  for (string &word:words) {
    cout<<word<<" ";

  }
}
void question6() {
  vector<int>nums;
  string fileName="number.txt";
  readFile(fileName,nums);
  display(nums,"numbers from file: ");
}

void question7() {
  vector<string>months={"Jan","Apr","May","Sept","Nov","Dec"};
  vector<string>::iterator iter=months.begin();
  iter++;
  iter=months.insert(iter,"Mar");
  iter=months.insert(iter,"Feb");
  iter+=4;//where it is pointing then insert the value
  iter=months.insert(iter,"Aug");
  iter=months.insert(iter,"Jul");
  iter=months.insert(iter,"Jun");
  iter+=4;
  iter=months.insert(iter,"Oct");

  for (string &month:months) {
    cout<<month<<" ";
  }
}
int areSameUntil(const vector<int> &v1, const vector<int> &v2) {
  int min=v1.size() < v2.size() ? v1.size() : v2.size();
  for (int i=0;i<min;i++) {
    if (v1[i] != v2[i]) {
      return i-1;
    }
    return i-1;
  }


}
void question8() {
  vector <int> vec1{1,2,3};
  vector <int> vec2{1,2,4};
  vector <int> vec3{4,5,6};
  vector <int> vec4{1,2,3,4,5};

  display(vec1);
  cout<<" and "<<endl;
  display(vec2);
  cout<< "Are same until element "<<areSameUntil(vec1,vec2)<<endl;

  display(vec1);
  cout<<" and "<<endl;
  display(vec3);
  cout<<" are same element "<<areSameUntil(vec1,vec3)<<endl;

  display(vec1);
  cout<<" and "<<endl;
  display(vec4);
  cout<<" are same element "<<areSameUntil(vec1,vec4)<<endl;

  display(vec1);
  cout<<" and "<<endl;
  display(vec1);
  cout<<" are same element "<<areSameUntil(vec1,vec1)<<endl;

}

bool areSameReverse(vector<int> &v1,vector<int> &v2) {
  vector<int>:: iterator it1=v1.begin();
  vector<int>:: const_reverse_iterator it2=v2.crbegin();
  while (it1!=v1.cend() && it2 != v2.crend()) {
    if (*it1 != *it2)
      return false;
    it1++;
    it2++;


  }
  return it1==v1.cend() && it2==v2.crend();
}
void question9() {
  vector<int> vic1{1,2,3};
  vector<int> vic2{3,2,1};

  display(vic1);
  cout<<" and "<<endl;
  display(vic2);
  cout<<" are the same element : "<<areSameReverse(vic1,vic2)<<endl;
}