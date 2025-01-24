package KPL.JAVA.service.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import KPL.JAVA.domain.Employee;
import KPL.JAVA.domain.Goat;
import KPL.JAVA.mapper.EmpolyeeMapper;
import KPL.JAVA.service.EmployeeService;

@Service
public class EmployeeServiceImpl implements EmployeeService{

	@Autowired
	private EmpolyeeMapper mapper;

	@Override
	public List<Goat> showALLEmployees() {
		// TODO Auto-generated method stub
		return mapper.selectAllEmployees();
	}

	@Override
	public List<Goat> selectOneEmployee(String name) {
		// TODO Auto-generated method stub
		return mapper.selectOneEmployee(name);
	}

	@Override
	public boolean insertOneGoat(String name, int goat, String department) {
		// TODO Auto-generated method stub
//		System.out.println("first:"+name+goat+department);
		Integer well=mapper.updateAfterInsert(name);
		if(well<=0) {
			System.out.println("update false");
		}
		else {
			mapper.insertOneGoat(name, goat, department);
			return true;
		}
		return false;
	}
	

}
