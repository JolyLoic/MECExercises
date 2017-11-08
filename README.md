# MEC
# Advanced C++ - Exercises

## You’re eligible to the free trip to the moon
You have a list of candidates, some have failed the challenge, some have succeeded it. This list is in registration order. The N first candidates that succeeded will receive a prize. Write an algorithm that will only leave those candidates in the list. If less than N candidates succeeded, the resulting list will contain less than N elements.

You should write this algorithm in STL style (with some test code), and ensure it is as generic as possible. What category should the involved iterators belong to? 

## You’re qualified for the final phase!
In a game, many candidates are performing several tests, leading them to having a grade. Write a code that will select the 10 candidates with the best grades that will be allowed to play the second round of the game. (in case of a tie, we don’t really care who is selected, just pick one).

Same questions as the previous exercise.
## BlaBlaTrip
You are asked to implement the following class diagram:

![BlaBlaTrip class diagram](/BlaBlaTrip.png) 

Focus only on the headers and on the data structure (forget all the member functions that would be useful for those classes, but still provide the necessary foundational functions, such as the destructors). Provide one separate header for each color. You code should compile.
## “Big” data
Look at the `BigData` program, and especially at the `BigData` class. What do you think of it? Propose some improvements/corrections (assuming the cache mechanism is relevant).

If the class was supposed to be used in a multithread environment, would you change your answer?
## Shape factory, take 2
Look at the shape factory in the `Factory` project (it correspond to a solution of an exercise during the Advanced C++ training). This factory is very specific to our use case. Can we make it more generic, and therefore reusable in another context? Write some code to show this.

## Easier map (?)
We have written the following utility function, to search a value in a map and provide a default if it’s not found:
```C++
string getWithDefault(map<string, string> const &map, string const &key, string const &defaultValue)
{
    auto it = map.find(key);
    return it == map.end() ? defaultValue : it->second;
}

int main()
{
    map<string, string> colors = { {"blue", "bleu"}, {"white", "blanc"}, {"red", "rouge"} };
    cout << "Red is " << getWithDefault(colors, "red", "unknown") << endl;
    cout << "Purple is " << getWithDefault(colors, "purple", "unknown") << endl;
    return 0;
}
```
Is this function correct? Is it as efficient as it can be? How would you improve it?

## Drawing a 3D scene
Look at the `SceneGraph` program (focusing on the main function). What do you think of the way this code is written? What are the pros & cons?

Wrap the 3rd party API in a way that makes writing such code more robust.
## Pythagoras
What do you think of the following code:
```C++
double hypothenuse(double a, double b)
{
    if (a <= 0 || b <= 0)
    {
        throw new exception("Invalid data");
    }
    return sqrt(a*a + b*b);
}

void pythagoras()
{
    auto drawing = R"(
     |\             
     | \            
     |  \           
 a   |   \ c        
     |    \         
     |     \        
     |      \       
     |       \      
     ----------     
          b         
)";

    cout << drawing << endl;

    cout << "a: ";
    double a;
    cin >> a;
    cout << "b: ";
    double b;
    cin >> b;
    cout << "c: " << hypothenuse(a, b) << endl;
}
```

## Pandemic, the game
You are assigned on a game project. The main idea behind the game is to simulate the propagation and mutation of diseases, with the goal to destroy mankind. Currently, the game is in early prototype phase, but the lead developer tells you that it might contain some memory leaks.

Your task is to detect then expunge those memory leaks. The source code is in the `Pandemic` program. There are some extra comments in this code that require action.

## Benchmark
Write the following algorithm (credits after the exercise has been done):
Generate N random integers, and insert them in a sequence so that each is inserted in its proper position in the numerical order. `5 1 4 2` gives:
```
5
1 5
1 4 5
1 2 4 5
``` 
Remove elements one at a time by picking a random position in the sequence and removing the element there. Positions `1 2 0 0` gives:
```
1 2 4 5
1 4 5
1 4
4
```
For which value of N do you think it is better to use a list than a vector as the underlying sequence?
Write some code to check that. This exercise is as much about writing the benchmark as about its conclusion, so please write it as cleanly as possible.

## GardenCraft
You are working on the new GardenCraft, an open world game where you can plant and grow everything necessary to build an environment sheltered from the harsh nature (and rampaging zombies). 

![GardenCraft class diagram](/GardenCraftUML.png)

The main loop of the program looks like the following pseudo-code:
```C++
int main()
{
    std::vector<Stuff*> allStuff;
    while (true)
    {
        for (auto &stuff : allStuff)
        {
            stuff->nextStep();
        }
        Actions actions;
        for (auto &stuff : allStuff)
        {
            if (stuff->isSentient())
            {
                actions.push_back(stuff->selectNextAction());
            }
        }
        for (auto &action : actions)
        {
            action.apply();
        }
        allStuff.erase(
            remove_if(allStuff.begin(), allStuff.end(), 
                [](auto s) {return !s->isAlive(); }),
            allStuff.end());
    }
    return 0;
}
```

The program is working correctly at first, but as more game elements are added, things start to become too slow (or, put another way, in order to keep an acceptable framerate, we have to drastically reduce the number of elements compared to what we first wanted to do). 

Can you suggest what might be a source of bad performances here? Can you spot a violation of a design principle too? 

Can you propose an alternative architecture that does not have those issues? What other drawbacks does it have?

## Is shared\_ptr thread-safe ?
What does this question even mean? What is the answer?


