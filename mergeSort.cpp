/* 
    implemented merge sort algorithm in c++ using std::vector and rand() funtion
    chose vector to overcome outofbound overflow error 
    rand() to generate random numbers to use sort algorithm ,srand(time(0)) also seeded it with time 
*/
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <vector>

// merge function is to merge left and right array elments to input array 
    void merge(std::vector<int> &arr,std::vector<int> &lArr,std::vector<int> &rArr){
        // storing size values for repetitive use
        int lsize = lArr.size();
        int rsize = rArr.size();

        // delaring indexing variables for looping  i for lArr,j for rArr, k for main array 
        int i = 0,j = 0,k = 0;

        // looping through the already sorted lArr and rArr and merging(over writting new sorted elements)
        while (i < lsize && j < rsize){
            // if the lArr i'th element is smaller then rArrs j'th element that its copid to input arr
            if (lArr.at(i) < rArr.at(j)){
                arr.at(k) = lArr.at(i);
                i++; // as the lArr i'th element is copied , its i'th element(index) is incremented to next element
                     // we dont increment rArr's j index element as we didn't copy it to input arr still
            }
            // else rArr is must smaller or equal then its assigned to inputArr 
            else {
                arr.at(k) = rArr.at(j);
                j++;// if lArr array isn't copied then the rArr's jth element must be copied to input arr
            }
            k++; // after the if else condition difinitely one element will be copied so k is increment 
                // so, the next element is copied will get copied in unsorted part
        }
        // while merging there are some chances for lArr or Rarr left with some element so we will assign those elemtns to arr
        while (i < lsize){
            arr.at(k) = lArr.at(i);
            i++;
            k++;
        }
        // if array elements are left over then 
        while(j < rsize){
            arr.at(k) = rArr.at(j);
            j++;
            k++;
        }
    }

 std::vector<int> mergeSort(std::vector<int> &arr){
    if (arr.size() <= 1){
        return arr;
    }
    // mid creating left and right array
    int mid = arr.size() / 2;
    std::vector<int> lArr(mid);
    std::vector<int> rArr(arr.size() - mid);
    
    // copying elements lArr
    for (int i = 0; i < lArr.size(); i +=1){
        lArr.at(i) = arr.at(i);
    }
    // copying elements for the right array
    for (int i = 0; i < rArr.size(); i +=1){
        rArr.at(i) = arr.at(mid + i);
    }
    // recurive calls
    mergeSort(lArr);
    mergeSort(rArr);

    // merge function 
    merge(arr,lArr,rArr);
    
}

int main(int argc,char * argv[]){
    // seeding time to the random genrrator
    srand(time(0));
    std::vector <int> arr (10.);
    for (int i = 0; i < arr.size(); i +=1){
        arr.at(i) = rand() % 10000;
    }
    std::cout << "before sorting" << std::endl;
    int i = 0;
    for (int num : arr){
        std::cout << ++i << ") "<<num << std::endl;
    }

    mergeSort(arr);
    std::cout << "after sorting" << std::endl;
    int j = 0;
    for (int num : arr){
        std::cout << ++j  << ") "<< num << std::endl;
    }
}