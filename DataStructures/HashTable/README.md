
 NOTE: This README is an  overview on what a Hashtable is.

What is a Hash Table?
 \
	A  HashTable is a data structure that stores values by mapping those values with keys. Its basic implementation usually consists of an vector<(key,value)>  in which a value  and its key is stored depending on the key it has. \
           Each key is created by using a hash function on that value and then mapping that value to that location on the array.\
	(NOTE: There are better ways to implement the table aspect of HashTable which will be discussed further down)
       
           ex) if value = "jon", and hashfunction(value) = 4, then (jon,4) will get stored at vector.at(4). 

How it works:

	As stated before the general idea of a Hash table is that it takes a value and then runs it through a hash function to get a key. the value is then stored at the location of the key.\
	To understand more on how it works lets discuss the two major parts of a hash table: Hash function and the table itself.
           
		1. Hash Function:
			
			A Hash Function is a fairly simple concept. All the function does is create a key that will be used to store your value and same key into the location of your table at key.\
			Hash Functions are hard to create so in general so usually  you just find one online making sure to cite where you got it from. A good Hash Function has a sense of randomization\
			and produces a minimum amount of collisions. 

		2. Hash Table: 
			The Best way to implement a Hash Table is to create a vector< (value, index)* >. ( explained in collision section.)

			
	the Insertion on a Hash table is very simple.The Insertion process works by storing the value key pair and inserting it at location(key). 
	so why is there a need to make the Hashtable a array of pointers rather than an array of arrays? The reason for this is because of Collisions

	What are collisions?

		collision is the event when two values get paired to the same key. 
		Example what if both values "jon" and "sam" get the key 4? 
		In the basic implementation the method "linear probing" is used. This method stores the value into the next available location. 
		For example, if \'91jon\'92 is stored at four then "sam" would be stored at  15. Here is the issue.  One could see the problem when \
		imagining 1000 values being mapped to key 4. 

		This is why  a implementation of vector<(value, index)* > is better.
		This implementation takes the benefits of a linked list and an array. 
           	           	-Takes the characteristic of random access from an array
				-Takes the dynamism of a linked list.
			

https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250"}}{\fldrslt \cf0 https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
https://www.youtube.com/watch?v=2wyCY1sX9II"}}{\fldrslt https://www.youtube.com/watch?v=2wyCY1sX9II
https://stackoverflow.com/questions/34595/what-is-a-good-hash-function"}}{\fldrslt https://stackoverflow.com/questions/34595/what-is-a-good-hash-function
