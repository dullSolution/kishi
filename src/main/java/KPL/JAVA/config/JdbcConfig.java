package KPL.JAVA.config;

import javax.sql.DataSource;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.PropertySource;

import com.alibaba.druid.pool.DruidDataSource;

@PropertySource("classpath:db.properties")
public class JdbcConfig {

	@Value("${jdbc.driverClass}")
	private String driver;
	
	@Value("${jdbc.jdbcUrl}")
	private String url;
	
	@Value("${jdbc.user}")
	private String userName;
	
	@Value("${jdbc.password}")
	private  String password;
	
	@Bean("dataSource")
	public DataSource getDataSource() {
		DruidDataSource ds =new DruidDataSource();
		
		ds.setDriverClassName(driver);
		ds.setUrl(url);
		ds.setUsername(userName);
		ds.setPassword(password);
		
		return ds;
	}
}
