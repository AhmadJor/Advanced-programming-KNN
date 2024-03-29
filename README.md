# Advanced-programming-KNN

<h1> How to run: </h1>

```commandline
make
./a.out 3 datasets/iris/iris_classified.csv MAN
```

<h1> Implementation</h1>
We used an abstract DistanceFunction class, which our distance function implemented,
Got the needed Distance Function from the command line arguments, set the function accordingly:

```c++
DistanceFunction *function;
if (distanceInput.compare("AUC") == 0) {
    function = new Euclidean;
} else if (distanceInput.compare("MAN") == 0)
    ...
```

Then we read our input file and converted it to a vector of `Object` objects which include data(for example flower measurements) and names. <br>
In our input function we read 1 line from cin, we then used a split function that we implemented to split the line
and push the inputs into a float vector. <br>
We created a map of `<string, float>` that corresponds to object names and distances from the input vector,
and calculated the distances, took the k closest names and made a map of `<string, int>` which corresponds to name and number of occurrences.
<br>
Finally, we took the maximum from that map by number of occurrences and printed the name. <br>
All of this is done in a loop, until the user decides to exit.
