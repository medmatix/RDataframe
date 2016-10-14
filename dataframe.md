##An R-type dataframe data-structure class for C++
@author David York
 
@date Saturday August 13, 2016
 
@version 0.8
  
  
@brief This creates a datatype "dataframe" modeled on the R language datatype. Initial memory order is simulated or forced column major.
  
The Dataframe class is an R-like data structure serving as a container for a dataset to be used in data analysis procedures.
  
It consists of fields in support of a set of variables contained in Node structures as a vector<Node>. The Node class is defined as an external dependency of the dataframe. It should be thought of as a table like structure with the columns containing the variable "Nodes" and the rows containing the observation sets of related variables.
  
Class methods maintain and manipulate the dataframe and it's observations and variable.
  
![Class Diagram](Dataframe_Class.svg)
  
&copy; 2016 David York
