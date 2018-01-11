#ifndef DIMPARAM_H
#define DIMPARAM_H

#include "TCLog.h"
#include <exception>

namespace Dimensions
{ 

	enum Units
	{
		adimensional,
		sec,
		m,
		kg,	
		rad,
		rational
	};

	enum ExceptionType
	{
		NoUnits,
		NoMatchingUnits,
		divisionBy0
	};

	class WrongUnitsException : public std::exception
	{
		ExceptionType m_type;
		virtual const char* what() const throw()
		{
			switch (m_type)
			{
			case NoUnits:
				return "No units set";
				break;
			case NoMatchingUnits:
				return "Units don't match";
				break;
			case divisionBy0:
				return "Division by 0 detected";
				break;
			default:
				return "Undefined units management exception";
				break;
			}
		}

	public:
		WrongUnitsException(ExceptionType i_type) : m_type(i_type) { }
		int getType() const { return m_type; }
	};

	template <class T>
	class DimParam {
	
	public:
		
		// Basic constructors
		DimParam();
		DimParam(Units i_units);
		DimParam(T i_value, Units i_units);
		~DimParam();
	
		// Overload operations (assignment, copy, subtraction, addition, multiplication, division, ...)

		// Copy constructor
		DimParam<T>(const DimParam<T>& i_inputParam);

		// Copy assignment constructor
		DimParam<T>& operator= (const DimParam<T>& i_inputParam);

		// Move assignment constructor
		DimParam<T>& operator= (const DimParam<T>&& i_inputParam);

		// Addition
		DimParam<T> operator+ (const DimParam<T>& i_addedParam);

		// Substraction
		DimParam<T> operator- (const DimParam<T>& i_substractedParam);

		// Multiplication
		DimParam<T> operator* (const DimParam<T>& i_multipliedParam);
		DimParam<T> operator* (const T& i_multipliedParam);

		// Division
		DimParam<T> operator/ (const DimParam<T>& i_divisorParam);
		DimParam<T> operator/ (const T& i_divisorParam);

		// Comparison
		bool operator== (const DimParam<T>& i_otherParam);
		bool operator== (const T& i_otherParam);

		// Check Units function
		bool checkUnits(const DimParam<T>& i_inputParam);

		// Getters
		Units getUnits() const { return m_units; }

		// Setters
		void setUnits(Units i_units) { 
			LOG(Logging::Level::STATUS, "DimParam", "Modifying units from " << m_units << " to " << i_units << std::endl);
			m_units = i_units; }

	protected:
		T m_value;
		Units m_units;
	
	};

	// Define commonly used template initializations
	template class DimParam<int>;
	template class DimParam<float>;
	template class DimParam<double>;

	// Define commonly used types as typedefs
	typedef DimParam<int> DimInt;
	typedef DimParam<float> DimFloat;
	typedef DimParam<double> DimDouble;
}
#endif //DIMPARAM_H