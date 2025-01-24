package KPL.JAVA.service;

import java.util.List;

import KPL.JAVA.domain.Student;

public interface StudentService {

	Student login(Student student);
	
	List<Student> show();
	
	void deleted2deleted();
}
