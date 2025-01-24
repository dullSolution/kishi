package KPL.JAVA.config;

import javax.sql.DataSource;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Import;
import org.springframework.jdbc.datasource.DataSourceTransactionManager;
import org.springframework.stereotype.Component;
import org.springframework.transaction.annotation.EnableTransactionManagement;

@EnableTransactionManagement
@ComponentScan("KPL.JAVA.service")
@Import({MybatisConfig.class,JdbcConfig.class})
@Configuration
public class SpringConfig {

	public DataSourceTransactionManager getDataSourceTransactionManager(
			@Autowired DataSource dataSource) {
		
		DataSourceTransactionManager ddd=new DataSourceTransactionManager();
		ddd.setDataSource(dataSource);
		return ddd;
	}
	
}
