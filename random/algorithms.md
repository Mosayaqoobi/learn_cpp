# Vectors

the overview of all its member functions, and others

1. reserve()
    - this function is used to allocated an x amount of memory 
into the heap so it doesn't have to reallocate memory somewhere
else when the capacity is reached. 
    - Good for when you know the total size of what the vector could be
```c++
vector.reserve(x)   // x is the capacity to pre allocate    
```
2. at()
    - This function takes an index (pos) as argument, and gives you the
element that lives in that index, otherwise will throw an
std::out_of_range
```c++
vector.at(x) //x is the index of the element you want
```
3. .data()
   - This function returns a pointer to the first element of the vector