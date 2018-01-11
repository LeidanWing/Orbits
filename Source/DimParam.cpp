#include "DimParam.h"


namespace Dimensions 
{

	template<class T>
	DimParam<T>::DimParam()
	{
		LOG(Logging::Level::ERROR, "DimParam", "No units specified" << std::endl);
		WrongUnitsException exception(Dimensions::NoUnits);
		throw exception;
	}

	template<class T>
	DimParam<T>::DimParam(Units i_units) : m_units(i_units), m_value(static_cast<T>(0))
	{
		LOG(Logging::Level::DEBUG, "DimParam", "Created parameter of type : " << typeid(m_value).name() << ", with unitsID : " << m_units << std::endl)
	}

	template<class T>
	DimParam<T>::DimParam(T i_value, Units i_units) : DimParam<T>(i_units)
	{
		m_value = i_value;
	}

	template<class T>
	DimParam<T>::~DimParam()
	{
		LOG(Logging::Level::DEBUG, "DimParam", "Deleted parameter"<< std::endl);
	}

	// Copy constructor
	template<class T>
	DimParam<T>::DimParam(const DimParam<T>& i_inputParam)
	{
		LOG(Logging::Level::DEBUG, "DimParam", "Calling copy constructor" <<std::endl)
		if (checkUnits(i_inputParam))
		{
			m_value = i_inputParam.m_value;
		}
		else
		{
			//Should not reach this
		}
	}

	// Copy assignment
	template<class T>
	DimParam<T>& DimParam<T>::operator=(const DimParam<T>& i_inputParam)
	{
		LOG(Logging::Level::DEBUG, "DimParam", "Calling copy assignment" << std::endl)
		if (checkUnits(i_inputParam))
		{
			m_value = i_inputParam.m_value;
		}
		else
		{
			// Should not reach this
		}
		return *this;
	}

	// Move assignment
	template<class T>
	DimParam<T>& DimParam<T>::operator=(const DimParam<T>&& i_inputParam)
	{
		LOG(Logging::Level::DEBUG, "DimParam", "Calling move assignment" << std::endl)
			if (checkUnits(i_inputParam))
			{
				m_value = i_inputParam.m_value;
			}
			else
			{
				// Should not reach this
			}
		return *this;
	}

	template<class T>
	DimParam<T> DimParam<T>::operator+(const DimParam<T>& i_addedParam)
	{
		if (checkUnits(i_addedParam))
		{
			return DimParam<T>(m_value + i_addedParam.m_value, m_units);
		}
	}

	template<class T>
	DimParam<T> DimParam<T>::operator-(const DimParam<T>& i_substractedParam)
	{
		if (checkUnits(i_substractedParam))
		{
			return DimParam<T>(m_value - i_substractedParam.m_value, m_units);
		}
	}

	template<class T>
	DimParam<T> DimParam<T>::operator*(const DimParam<T>& i_multipliedParam)
	{
		LOG(Logging::Level::STATUS, "DimParam", "Multiplying unitsID " << m_units << " to unitsID " << i_multipliedParam.m_units << std::endl);
		return DimParam<T>(m_value * i_multipliedParam.m_value, rational);
	}

	template<class T>
	DimParam<T> DimParam<T>::operator*(const T & i_multipliedParam)
	{
		return DimParam<T>(m_value * i_multipliedParam, m_units);
	}

	template<class T>
	DimParam<T> DimParam<T>::operator/(const DimParam<T>& i_divisorParam)
	{
		LOG(Logging::Level::STATUS, "DimParam", "Dividing unitsID " << m_units << " by unitsID " << i_divisorParam.m_units << std::endl);
		if (i_divisorParam.m_value == T(0))
		{
			LOG(Logging::Level::ERROR, "DimParam", "Division by 0" << std::endl);
			WrongUnitsException exception(Dimensions::divisionBy0);
			throw exception;
		}
		else
		{
			return DimParam<T>(m_value / i_divisorParam.m_value, rational);
		}
	}

	template<class T>
	DimParam<T> DimParam<T>::operator/(const T & i_divisorParam)
	{
		if (i_divisorParam == T(0))
		{
			LOG(Logging::Level::ERROR, "DimParam", "Division by 0" << std::endl);
			WrongUnitsException exception(Dimensions::divisionBy0);
			throw exception;
		}
		else
		{
			return DimParam<T>(m_value / i_divisorParam, m_units);
		}
	}

	template<class T>
	bool DimParam<T>::operator==(const DimParam<T>& i_otherParam)
	{
		if (checkUnits(i_otherParam))
		{
			return m_value == i_otherParam.m_value;
		}
	}

	template<class T>
	bool DimParam<T>::operator==(const T& i_otherParam)
	{
		return m_value == i_otherParam;
	}

	template<class T>
	bool DimParam<T>::checkUnits(const DimParam<T>& i_inputParam)
	{
		if (i_inputParam.m_units == Dimensions::rational)
		{
			LOG(Logging::Level::STATUS, "DimParam", "Assigning value coming from a dimensional rational expression to " << m_units << std::endl);
			return true;
		}
		if (m_units != i_inputParam.m_units)
		{
			LOG(Logging::Level::ERROR, "DimParam", "UnitID " << m_units << " and " << i_inputParam.m_units << " do not match" << std::endl);
			WrongUnitsException exception(Dimensions::NoMatchingUnits);
			throw exception;
		}
		else
		{
			return true;
		}
	}
}

