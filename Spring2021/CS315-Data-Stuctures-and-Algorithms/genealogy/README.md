# Genealogy
### By: Brennen Green
### CS315-Spring 2021 Assignment 5


## __Program Description__

Given an input .txt file with commands. It will process all commands
in the file. 

__Output__: The output of commands given line by line in input file.

```
Family 12 has husband 0, wife 0, and children 6.
Relation: person 1 -> family 2 -> person 2 -> family 3 -> person 10 -> family 14 -> person 39 -> family 19 -> person 55
```

__Command Format__:

Family n Husband n Wife n Child n Child n ...

Relate n n

Where n is some integer [1, 99]

__Usage__: `./genealogy [Expects input data on stream]`

Example Usage: `./genealogy < commands.txt`

### __Extra Credit Information__
For this assignment I did three pieces of extra credit.

To see these in action, please run this program with the
personal input data I provided.

`.genealogy < extra-credit-data.txt > extra-credit-run.out`

As extra credit, I implemented:

1. Two new commands:

Ancestors n: Displays all the ancestors of person n in the familygraph.

Descendants n: Displays all the descendants of person n in the familygraph

2. I also implemented same sex marriages, which can be built using the typical
Family command.

Same-Sex Examples:
```
Family 1 Husband 1 Husband 2 Child 3 4 5
Family 2 Wife 3 Wife 10 Child 33 44
```

### __NOTE ON UNION FIND__:

My Union-Find data structure does not take into account the height of individual
paths. Instead it uses path compression by pointing each individual node to one
root representative. Dr. Finkel told me that this is an acceptable as well.

## __Compilation__

Compilation made easy via the Makefile.

Just type `make` in the command line. It'll even
run it once for you and pipe output to tmpRun.out.

## __Function and Structure Documentation__

__MAIN FUNCTIONS__

```
int parse_command(std::string line, FamilyGraph * graph)
Input: A line of characters, a FamilyGraph.
Output: Command output.
Returns: 0 if successful, 1 otherwise.
```

__FAMILY GRAPH FUNCTIONS__

```
FamilyGraph::print_family(int family_id)
Input: A family id which can be used to index families vector.
Outputs: The string representation of one given family.
```

```
FamilyGraph::make_family(int family_id, vector<Pair> heads,
                                          vector<int> children)
Input: Specific family id number, vector of heads (with id numbers),
   vector of children.
Ouput: Results of make family.
```

```
FamilyGraph::relationship(int person1, int person2)
Input: Two person identifying integers.
Outputs: The string representation of how person1 an person2 are related.
```

```
FamilyGraph::breadth_first_search(int person1, int person2)
Input: Two person identifying integers.
Outputs: The built path between two person vertices.
```

```
FamilyGraph::build_path(int person1, int person2, std::vector<int> prev)
Input: Two person identifiers, a vector of associated previous vertices.
Outputs: The built path between two vertices.
```

```
FamilyGraph::ancestors(int person)
Input: One person identifier.
Outputs: All known ancestors of one vertex (person).
```

```
FamilyGraph::descendants(int person)
Input: One person identifier.
Outputs: All known descendants of one vertex (person).
```

```
process_relate(FamilyGraph * graph, int person1, int person2)
Input: The graph to check relationship with, the two people to check.
Outputs: Results of relating two people, will be the shortest path
between the two people if they are related.
```

```
process_family()
Description: Wrapper for FamilyGraph::make_family().
```

```
process_descendants()
Description: Wrapper for FamilyGraph::descendants().
```

```
process_ancestors()
Description: Wrapper for FamilyGraph::ancestors().
```


__FAMILY FUNCTIONS__

```
Family::get_unknown_gender()
Returns: String representation of the gender of unknown person.
```

```
std::vector<int> Family::get_persons()
Returns: A vector of person identifiers.
```

__PERSON FUNCTIONS__

```
get_direct_relation(Person * person1, Person * person2)
Input: Two pointers to a person object.
Returns: The identifier of the family that relates person1 and person2.
```

__QUEUE FUNCTIONS__

```
Queue::enqueue(int p)
Input: An integer to add to the queue (represents a person).
```

```
Queue::dequeue()
Returns: An integer from the front of the queue.
```

__COMPONENT FUNCTIONS__

```
Component::join(Component other_component)
Input: A component to join to this component.
```

```
Component::find(Person * person)
Input: A pointer to a person to look for in this component.
Returns: true if the person is found in the component, false otherwise.
```

__UNIONFIND FUNCTIONS__

```
Component UnionFind::find(Person * a)
Input: A pointer to a person to look for in the union-find.
Returns: The component the person is in, if found, or an empty component.
```

```
UnionFind::union_f(Component a, Component b)
Input: Two components to union into one component.
```