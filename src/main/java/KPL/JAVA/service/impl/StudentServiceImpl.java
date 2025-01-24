package KPL.JAVA.service.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import KPL.JAVA.domain.Student;
import KPL.JAVA.mapper.StudentMapper;
import KPL.JAVA.service.StudentService;

@Service
public class StudentServiceImpl implements StudentService{

	
	
	@Override
	public List<Student> show() {
		// TODO Auto-generated method stub
		return mapper.show();
	}

	@Autowired
	private StudentMapper mapper;
	
	@Override
	public Student login(Student student) {
		// TODO Auto-generated method stub
		return mapper.login(student);
	}

	@Override
	public void deleted2deleted() {
//		System.out.println("well");
		// TODO Auto-generated method stub
		mapper.deleted2deleted();
	}

	
	
	
}
