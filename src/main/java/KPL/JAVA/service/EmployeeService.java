package KPL.JAVA.service;

import java.util.List;

import KPL.JAVA.domain.Employee;
import KPL.JAVA.domain.Goat;

public interface EmployeeService {

	List<Goat> showALLEmployees();
	
	List<Goat> selectOneEmployee(String name);
	
	boolean insertOneGoat(String name,int goat,String department);
}
