/** \file
 * \page Node
 *
 * Source Files:
 *
 * *node.cpp and node.h*
 *
 * (see also *dataframe .cpp*, *FileUtilsCpp .cpp*, *category .cpp* and *main .cpp*.)
 *
 * ##An Abstract Node Class to contain a variable pointer
 *
 * @author David York
 * @date Sunday September 18, 2016
 * @version 0.8
 *
 * @brief This creates an Abstract Node class to contain the meta-data, and a
 *  pointer to the data of a variable. The Variable Type Nodes ultimately inherit
 *  from the node as their base class, and ultimately they form part of the
 *  dataframe class which is simply a vector of nodes.
 *
 *
 *  In an abstract sense, the nodes are the variables, as contained for example
 *  in a vector of nodes which is the dataframe structure.
 *
 *  The meta-data defines the variable broadly and a pointer to a vector<type>
 *  containing the observation data of each dataframe.cpp" variable.
 *
 *  Class methods allow maintenance and manipulation of the variable it's data
 *  as to variable name, variable (data) type variable id (or position) within
 *  any containing structure and the observation data itself.
 *
 * &copy; 2016 David York
 */

#include "node.h"




void node::serialize()
{
    //serialize node object
}

void node::display()
{
    //display node to stdout
}

string node::tostring()
{
    //output node as (continuous) string stream
    string nodeStr = "";
    return nodeStr;
}
