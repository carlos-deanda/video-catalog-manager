#include "OOPUtils.h"
#include <limits>

void OOPUtils::staticTest() {
    std::cout << "DOING STUFF IN A STATIC METHOD!" << std::endl;
}
void OOPUtils::cleanCin() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
}

// receive a string, break it apart using the delimeter as a breakpoint,
// return a vector with the parts

std::vector<std::string> OOPUtils::split(const std::string&  source, const std::string& delimeter) {
    std::vector<std::string> result;
    
    int start = 0;
    int end;
    
    // go through the string search for the location of delimeter and substring
    // (substring is creating a string that is a part of another string)
    
    
    //there is a find method within the string that returns the location
    // of a string within the string.
    
    int pos = source.find(delimeter);
    
    if(pos == std::string::npos){
        
        std::cout << "STRING NOT FOUND" << std::endl;
    }
    else{
        std::cout << "string found at position: " << pos << std::endl;
    }
    
    // what we need to do is serach for the indexes
    end = source.find(delimeter);
    
    // optimize this in a couple of years!
    while (end != std::string::npos){
        
        // get slice
        std::string part = source.substr(start, end - start);
        
        // save slice
        result.push_back(part);
        
        // we need a new start!
        start = end + delimeter.length();
        
        // search for new end position
        end = source.find(delimeter, start);
    }
    
    // add the last part
    result.push_back(source.substr(start));
    
    return result;
}
