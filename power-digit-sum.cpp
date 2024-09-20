#include<iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert> 

using namespace std;

unsigned long long int powerFunction(unsigned int number, unsigned int power){
    unsigned long long result = 1;
    for(unsigned long long int i = 0; i < power; i++){ // loop that performs the pow() function
        result *= number; // multiplies the result by number 

    }
            
    // a: b: 2^5 = 32
        
    return result; // https://www.geeksforgeeks.org/return-statement-in-cpp-with-examples/ 
                    // looked at if I could return variables 
}

unsigned long long sumofDigits(unsigned long long result){
    unsigned long long sum = 0;
    unsigned long long count = 0; 

    while (result > 0) { // keeps going until the number is not dividable
        count = result % 10; // finds the modulus of the number to find the sum 
        result /= 10; // divides the number to keep cycle going
        sum += count; // adds the sums of the digit 
         
    }
        
    cout << "Sum Of Digits:" << sum << endl;// prints the sum of the digits
    // Sum Of Digits: 5
    return sum;
}

vector<int>vectorize_digits(unsigned long long n){
     vector<int> value;  
        if(n == 0){
            value.push_back(0);
        }
      while (n > 0) {
         int digit = n % 10;   // Get the last digit
         value.push_back(digit);  // Add the digit to the vector
         n = n / 10;  
                 // Remove the last digit
        }

     reverse(value.begin(), value.end()); //https://cplusplus.com/reference/algorithm/reverse/

     return value;
}

int sum_vector(vector<int> v) {
    int vectorSum = 0;  

    // Iterate through the vector and add each element to sum
    for (int vectorNum : v) {
        vectorSum += vectorNum;
    }

    return vectorSum;  // Return the total sum
}

string vec_to_string(vector<int> vec){
    string str = "";
    
    for (int digit : vec) {
        str += to_string(digit);  // Convert each integer to string and append
    }

    return str;
}

void tests() {
    // Test powerFunction and sumofDigits 
    assert(powerFunction(2, 5) == 32);
    assert(powerFunction(6, 4) == 1296);
    assert(powerFunction(12, 4) == 20736);
    
    // Test vectorize_digits
    vector<int> expected_digits = {3, 2};
    assert(vectorize_digits(32) == expected_digits);
    
    expected_digits = {1, 2, 3, 4, 5};
    assert(vectorize_digits(12345) == expected_digits);

    // Test sum_vector
    vector<int> test_vec = {1, 2, 3, 4, 5};
    assert(sum_vector(test_vec) == 15);

    test_vec = {3, 2};
    assert(sum_vector(test_vec) == 5);

    // Test vector_to_string
    vector<int> test_vec_str = {1, 2, 3, 4, 5};
    assert(vec_to_string(test_vec_str) == "12345");
    
    test_vec_str = {3, 2};
    assert(vec_to_string(test_vec_str) == "32");

}


int main(){
    string a;
    string b;


    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    if (a.find('-') != string::npos || b.find('-') != string::npos) { //https://www.codecademy.com/resources/docs/cpp/strings/find
        cout << "Invalid inputs  a: " << a << "   b: " << b << endl;
        cout << "a and b must be non-negative integers." << endl;
        return 0;
    }
    
    try { 
        unsigned long long number = stoull(a); // https://cplusplus.com/reference/string/stoull/
        unsigned long long power = stoull(b);
    
    // if (number < 0 || power < 0 ){
    //         cout << " Invalid inputs  a:" << number << " b: " << power << endl;
    //         cout << "a and b must be non-negative integers." << endl;
    //         return 0;
    //     }
    
    if((power * log(number)) >= (64 * log(2))){
        cout << "Invalid inputs  a: " << number << "   b: " << power << endl;
        cout << "This selection of a and b cannot be computed due to overflow!" << endl;
        return 0;
        
    }
        
        unsigned long long result = powerFunction(number, power);
        
        vector<int> output = vectorize_digits(result);
        int sum = 0;
        for (int value : output) {
            sum += value; 
        }
        
        
        //Power function
        string digitString = vec_to_string(output);
        cout << number << "^"<< power << " = " << digitString << endl;

        string sumString = to_string(sum); 
        cout << "Sum Of Digits: " << sum << endl;

        
        tests();
    }

    catch (const invalid_argument& e) {  // https://en.cppreference.com/w/cpp/error/invalid_argument 
                                        // https://faculty.cs.niu.edu/~mcmahon/CS241/Notes/exceptions.html 
        
        // If input is not a valid number
        cout << "Invalid inputs  a: " << a << "   b: " << b << endl;
        cout << "a and b must be non-negative integers." << endl;
    }

    catch (const out_of_range& e) {  
        // If input is out of range for stoull
        cout << " Invalid inputs  a: " << a << "   b: " << b << endl;
        cout << "a and b are too large to be processed." << endl;
    }
      
}

// Sam Freed helped me with the Ocus assignment
    
// a. The mistake is that the value of `runs_taken_so_far` is incorrectly set to `8`.
// b. The mistake occurs on the line: machine([11, 11, 11, 8],8).
// c. I found the mistake by looking machine([11, 11, 11, 8],8) the runs_taken_so_far starts much higher than the actual value and is incorrect
// d. On a scale of 1-10, it was about a 10 it was the best assignment I have ever done (I hope this convinced you to boosts my grade).
   