#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
//Using pi from math.h
#include <math.h>

using namespace std;

int lineCount = 0;
float mean = 0;
float Variance(string userFileName);
float stdDev(float Variance);
float Gaussian(float mean, float variance);
ofstream outStream;
float bigramNum = 0;
string tryAgain = "yes";

int main(int argc, char** argv) {

  srand(time(NULL));
  // Take a text file as an input from user
  outStream.open("caitlin.out");
  while(tryAgain == "yes") {

  string line = "";
  int countA = 0;
  int countC = 0;
  int countT = 0;
  int countG = 0;
  int DNAsum = 0;
  int aa = 0; int cc = 0; int gg = 0; int tt = 0;
  int ac = 0; int at = 0; int ag = 0;
  int ca = 0; int ct = 0; int cg = 0;
  int ta = 0; int tc = 0; int tg = 0;
  int ga = 0; int gc = 0; int gt = 0;


  ifstream inStream;
  string userFileName;
  userFileName = argv[1];
  //Open the file that the user gave us
  inStream.open(userFileName);

  //Check if we can open the file the user gave us
  if(!inStream) {
    cout << "Cannot open this file. Choose again, thanks.\n";
  }

int numTotalChar = 0;

//While loop that goes through string
  while(getline(inStream, line)) {
    //Get number of lines in text file
    lineCount++;

    for(int i = 0; i < line.length(); ++i) {
      numTotalChar++;

//Change all inputs in string to lowercase
      string dnaPair = " ";
      dnaPair = string(1, tolower(line[i]));
      dnaPair += string(1, tolower(line[i+1]));

//Calculate the number of A,C,T, and G
      if(tolower(line[i]) == 'a')
        countA++;
      if(tolower(line[i]) == 'c')
        countC++;
      if(tolower(line[i]) == 't')
        countT++;
      if(tolower(line[i]) == 'g')
        countG++;

//Calculate the number of Bigrams in string
      if(dnaPair == "aa") {
        aa++;
        bigramNum++;
      }
      else if(dnaPair == "ac"){
        ac++;
        bigramNum++;
      }
      else if(dnaPair == "at"){
        at++;
        bigramNum++;
      }
      else if(dnaPair == "ag") {
        ag++;
        bigramNum++;
      }

      else if(dnaPair == "ca"){
        ca++;
        bigramNum++;
      }

      else if(dnaPair == "cc"){
        cc++;
        bigramNum++;
      }
      else if(dnaPair == "ct") {
        ct++;
        bigramNum++;
      }

      else if(dnaPair == "cg") {
        cg++;
        bigramNum++;
      }

      else if(dnaPair == "ga") {
        ga++;
        bigramNum++;
      }

      else if(dnaPair == "gc"){
        gc++;
        bigramNum++;
      }
      else if(dnaPair == "gt") {
        gt++;
        bigramNum++;
      }
      else if(dnaPair == "gg") {
        gg++;
        bigramNum++;
      }
      else if(dnaPair == "ta") {
        ta++;
        bigramNum++;
      }
      else if(dnaPair == "tc") {
        tc++;
        bigramNum++;
      }
      else if(dnaPair == "tg") {
        tg++;
        bigramNum++;
      }
      else if(dnaPair == "tt") {
        tt++;
        bigramNum++;
      }
    }
  }

  //Print the number of characters in text file
  cout << "Number of characters/Sum: " << numTotalChar << "\n";

  //Print the mean of the text file
  mean = numTotalChar / lineCount;
  cout << "Mean: " << mean << "\n";
  float variance = Variance(userFileName);
  cout << "Variance: " << variance << "\n";
  float stdDeviation = stdDev(variance);
  cout << "Standard Deviation: " << stdDeviation << "\n";


  //Output to caitlin.out
  outStream << "Caitlin Felts" << endl;
  outStream << "Student ID: 2318073" << endl;
  outStream << "CPSC-350-01" << endl;
  outStream << "COUNT OF A: " << countA << endl;
  outStream << "COUNT OF C: " << countC << endl;
  outStream << "COUNT OF T: " << countT << endl;
  outStream << "COUNT OF G: " << countG << endl;



  //Find the probability of each nucleotide
  outStream << "A:" << (float)countA / numTotalChar * 100 << "%" << endl;
  outStream << "C:" << (float)countC / numTotalChar * 100 << "%" << endl;
  outStream << "T:" << (float)countT / numTotalChar * 100 << "%" << endl;
  outStream << "G:" << (float)countG / numTotalChar * 100 << "%" << endl;
  outStream << "AA:" << aa / bigramNum * 100 << "%" << endl;
  outStream << "CC:" << cc / bigramNum * 100 << "%" << endl;
  outStream << "TT:" << tt / bigramNum * 100 << "%" << endl;
  outStream << "GG:" << gg / bigramNum * 100 << "%" << endl;
  outStream << "AC:" << ac / bigramNum * 100 << "%" << endl;
  outStream << "AT:" << at / bigramNum * 100 << "%" << endl;
  outStream << "AG:" << ag / bigramNum * 100 << "%" << endl;
  outStream << "CA:" << ca / bigramNum * 100 << "%" << endl;
  outStream << "CT:" << ct / bigramNum * 100 << "%" << endl;
  outStream << "CG:" << cg / bigramNum * 100 << "%" << endl;
  outStream << "TA:" << ta / bigramNum * 100 << "%" << endl;
  outStream << "TC:" << tc / bigramNum * 100 << "%" << endl;
  outStream << "TG:" << tg / bigramNum * 100 << "%" << endl;
  outStream << "GA:" << ga / bigramNum * 100 << "%" << endl;
  outStream << "GC:" << gc / bigramNum * 100 << "%" << endl;
  outStream << "GT:" << gt / bigramNum * 100 << "%" << endl;


  for(int i = 0; i < 1000; ++i) {
    float gd = Gaussian(mean, variance);
    int gaussA = ((float)countA / numTotalChar) * gd;
    int gaussC = ((float)countC / numTotalChar) * gd;
    int gaussT = ((float)countT / numTotalChar) * gd;
    int gaussG = ((float)countG / numTotalChar) * gd;

    string gaussString = "";

    for(int z = 0; z < gaussA; ++z) {
      gaussString += "a";
    }
    for(int z = 0; z < gaussC; ++z) {
      gaussString += "c";
    }
    for(int z = 0; z < gaussT; ++z) {
      gaussString += "t";
    }
    for(int z = 0; z < gaussG; ++z) {
      gaussString += "g";
    }

    //Put the string in caitlin.out
    outStream << gaussString << endl;
  }

//Ask user if they want to try another file
cout << "Do you want to try another file? (yes/no)";
cin >> tryAgain;

  if(tryAgain == "yes") {
    cout << "Enter text file name: ";
    cin >> userFileName;
  }
  lineCount = 0;
  bigramNum = 0;
  countA = 0;
  countC = 0;
  countT = 0;
  countG = 0;
  aa = 0;
  ac = 0;
  at = 0;
  ag = 0;
  ca = 0;
  cc = 0;
  ct = 0;
  cg = 0;
  ta = 0;
  tc = 0;
  tt = 0;
  tg = 0;
  ga = 0;
  gc = 0;
  gg = 0;
  gt = 0;

  if(!inStream) {
    cout << "Cannot open this file. Choose again, thanks.\n";
  }
}
outStream.close();
}

//Variance function
float Variance(string userFileName) {
  //Redeclaring inStream
  ifstream inStream;

  //Opening the user's text file
  inStream.open(userFileName);

  float sumOfDifference = 0;
  string fileLine;
  while(getline(inStream, fileLine)) {

    sumOfDifference += pow(fileLine.length() - mean, 2);


  }
  inStream.close();

  //Dividing sumOfDifference by # of lines - 1
  float variance = sumOfDifference / (lineCount - 1);
  return variance;

}
  //Standard Deviation function
float stdDev(float Variance) {
  float stdDeviation = sqrt(Variance);

  return stdDeviation;

}

//Gaussian distribution
float Gaussian(float mean, float variance) {
  float a = (float)rand() / (float)RAND_MAX;
  float b = (float)rand() / (float)RAND_MAX;

  float C = sqrt((-2) * log(a)) * cos(2*(M_PI)*b);
  float D = sqrt(variance) * C + mean;

  return D;
}
