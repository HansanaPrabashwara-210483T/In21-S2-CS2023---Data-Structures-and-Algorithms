/**
 * @file quicksort.cpp
 * @author D.G.Hansana Prabashwara (you@domain.com)
 * @brief Generate a array with random values and Find the running median. This program uses recursive quicksort algoritm. 
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



void swap_values(vector<int>& arr, int first_index, int second_index){
    int temp = arr[first_index];
    arr[first_index] = arr[second_index];
    arr[second_index] = temp;
}

/**
 * @brief This function returns the pivot index while changing the given array accordingly.
 * 
 * @param array 
 * @param begin_index 
 * @param end_index 
 * @return int 
 */

int pivot(vector<int>& array, int begin_index, int end_index){
    int pivot_value = array[end_index];
    int pivot_index = begin_index - 1;

    for(int element_index=begin_index; element_index<end_index; element_index++){
        if(array[element_index] < pivot_value){
            pivot_index ++;
            swap_values(array,element_index,pivot_index);
        }
    }
    pivot_index ++;
    swap_values(array, pivot_index, end_index);

    return pivot_index;
}



/**
 * @brief Sort a given unsorted list using insertion sort.
 * 
 * @param unsorted_array 
 * @return vector<int> 
 */
vector<int> sort_with_quicksort(vector<int>& unsorted_array, int begin_index, int end_index){
    if(end_index > begin_index){
        int pivot_index = pivot(unsorted_array,begin_index,end_index);
        sort_with_quicksort(unsorted_array,begin_index,pivot_index-1);
        sort_with_quicksort(unsorted_array,pivot_index+1, end_index);
    }
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
float find_the_median(vector<int>& unsorted_array, int begin_index, int end_index){
    vector<int> sorted_array= sort_with_quicksort(unsorted_array,begin_index, end_index);
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
        cout << find_the_median(iterative_list,0,i)<<"\n";
    }    
    
}   