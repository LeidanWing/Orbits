#IFNDEF DIMPARAM_H
#DEFINE DIMPARAM_H

template <class T>
class dimParam {
	
public:
	
	dimParam(T i_value, std::string i_units);
	
	// Overload operations (copy, subtraction, addition, multiplication, division, ...)
	
	
protected:
	T value;
	std::string m_units;
	
}

#ENDIF PARAM_H