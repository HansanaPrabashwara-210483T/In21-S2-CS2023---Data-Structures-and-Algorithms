/**
 * @file quicksort.cpp
 * @author D.G.Hansana Prabashwara (you@domain.com)
 * @brief Generate a array with random values and Find the running median. This program uses insertionsort algoritm to sort the given list. 
 * @version 0.1
 * @date 2023-03-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;


/**
 * @brief Create a array object 
 * 
 * @param elements_amount 
 * @return vector<int> 
 */
vector<int> create_array(int elements_amount){
    vector<int> array;
     for(int i = 0; i < elements_amount; ++i){
        array.push_back(rand());
    }
    return array;
}


/**
 * @brief Print the given list to the terminal 
 * 
 * @param array 
 */
void print_array(vector<int> array){
    string print_string = "[";
    for(int i : array){
        print_string += to_string(i) + ",";        
    }
    print_string.pop_back();
    print_string += "]      ";
    cout << print_string;
}


/**
 * @brief Sort a given unsorted list using insertion sort.
 * 
 * @param unsorted_array 
 * @return vector<int> 
 */
vector<int> sort_with_insertion(vector<int>& unsorted_array){
    int elements_amount = unsorted_array.size();
    
        
    int inserting_element = unsorted_array[unsorted_array.size()-1];
    int inner_loop_count=unsorted_array.size()-2;
    
    while(inner_loop_count>=0 && unsorted_array[inner_loop_count] > inserting_element){
        unsorted_array[inner_loop_count + 1] = unsorted_array[inner_loop_count];
        inner_loop_count = inner_loop_count - 1; 
    }
    unsorted_array[inner_loop_count+1] = inserting_element;
    // print_array(unsorted_array);
    
    return unsorted_array;
}


/**
 * @brief This function return the median of the given array after sorting it
 * 
 * @param unsorted_array 
 * @param begin_index 
 * @param end_index 
 * @return float 
 */
float find_the_median(vector<int>& unsorted_array){
    vector<int> sorted_array= sort_with_insertion(unsorted_array);
    float median ;
    if(sorted_array.size() % 2 == 1){
        median = sorted_array[floor(sorted_array.size()/2)];
    }else{
        median = ((float)sorted_array[sorted_array.size()/2] + (float)sorted_array[sorted_array.size()/2-1])/2.0;
    }
  
    print_array(sorted_array);
    
    return median;
}



int main(){
    vector<int> array = create_array(10);
    
    cout<< "Generated Array : ";
    print_array(array);
    cout << endl;
    
    vector<int> iterative_list = {};

    for(int i = 0; i < array.size() ;i++){
        iterative_list.push_back(array[i]);
        cout << find_the_median(iterative_list)<<"\n";
    }    
    
}   