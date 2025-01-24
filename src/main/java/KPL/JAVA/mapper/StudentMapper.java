package KPL.JAVA.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Result;
import org.apache.ibatis.annotations.ResultMap;
import org.apache.ibatis.annotations.Results;
import org.apache.ibatis.annotations.Select;

import KPL.JAVA.domain.Student;

public interface StudentMapper {

	@Select("select id,name,sno from tb_student where name=#{username} AND"+
			"password=#{password}")
	@Results(id="studentMap",value = {
			@Result(id=true,column = "id",property = "id"),
			@Result(column = "name",property = "name"),
			@Result(column = "password",property = "password"),
			@Result(column = "sno",property = "sno")
	})
	Student login(Student student);
	
	
	@Select("select name,sno from tb_student")
	@ResultMap("studentMap")
	List<Student> show();
	
	
	void deleted2deleted();
	
}
