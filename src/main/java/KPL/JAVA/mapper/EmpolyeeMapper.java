package KPL.JAVA.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Result;
import org.apache.ibatis.annotations.ResultMap;
import org.apache.ibatis.annotations.Results;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import KPL.JAVA.domain.Employee;
import KPL.JAVA.domain.Goat;

public interface EmpolyeeMapper {

	
	@Results(id = "goatMap",
			value= {
			@Result(column = "姓名",property = "name"),
			@Result(column = "绩效",property = "goat")
			})
	@Select("select 姓名,绩效 from vw_goat_simple order by 创建时间 desc")
	List<Goat> selectAllEmployees();
	
	@ResultMap("goatMap")
	@Select("select 姓名,绩效 from vw_goat_simple where 姓名 like concat('%',#{name },'%')")
	List<Goat> selectOneEmployee(String name);
	
	
	@Insert("insert into goat(uid,goat) values((SELECT u.uid from user as u where u.name =#{name } and u.department=#{department }),#{goat })")
//	@Insert({"<script>",
//			"INSERT INTO goat(uid,goat) values("
//			+ "(SELECT u.uid from user as u where u.name=#{name}"
//			+ "and u.department=#{department}),"
//			+"#{goat} )"
//			+"</script>"})
	boolean insertOneGoat(@Param("name") String name,@Param("goat") int goat,@Param("department") String department);
	
	@Update("update goat set deleted = 1 where uid=(select uid from user where name=#{name })")
	Integer updateAfterInsert(@Param("name") String name);
	
	
	
}
