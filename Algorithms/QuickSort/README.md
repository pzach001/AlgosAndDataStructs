How to run:

	A simple Makefile is provided. run make and then after use a.out executable

What is QuickSort:

	Quicksort is a very popular sorting algorithm. It is known for its efficiency in most cases

How it Works: 
      
 	Quick sort Works by going through these steps until the array is sorted.
		First you pick a random element in the array ( in my case it will be the last node of the array). We will define this as a pivot. 
		Then  you "partition the array. Every element that is less than the pivot will be placed before the pivot, every value greater than the pivot will be placed after. 
		you then will split up the array into subarrays and run the program recursively on them. The subarrays will be created from the pivot. 

Performance:
		
		The Best Case Performance would be:     O(NlogN) or O(N)
                The Worst Case Performance would be :   O(N^2)
                The Average Case Performance would be:  O(NlogN)

Why QuickSort over Mergesort?

		Quicksort is generally used over Mergesort in general due to quicksort not needing to dynamically allocate more memory for Arrays like Mergesort does. It's worse case performance is usually rare. 


            		           
