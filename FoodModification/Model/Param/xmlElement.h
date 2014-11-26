#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include <string>
#include <map>
#include <list>

using namespace std;

class XmlElement {

/*method*/
public:
	XmlElement();
/*property*/
private:
    string _name;
    string _value;
    map<string, string> _attributes;
    list<XmlElement> _childs;
};

#endif // XMLELEMENT_H
