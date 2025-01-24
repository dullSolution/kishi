package KPL.JAVA.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.DefaultServletHandlerConfigurer;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;
import org.springframework.web.servlet.config.annotation.PathMatchConfigurer;
import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;
import org.springframework.web.servlet.config.annotation.ViewResolverRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

@EnableWebMvc
@ComponentScan({ "KPL.JAVA.controller" })
@Configuration
public class SpringMvcConfig implements WebMvcConfigurer {

	@Override
	public void configureDefaultServletHandling(DefaultServletHandlerConfigurer configurer) {
		// TODO Auto-generated method stub
//		WebMvcConfigurer.super.configureDefaultServletHandling(configurer);
		configurer.enable();
	}

	@Override
	public void configureViewResolvers(ViewResolverRegistry registry) {
		// TODO Auto-generated method stub
//		WebMvcConfigurer.super.configureViewResolvers(registry);
		registry.jsp("/WEB-INF/", ".jsp");

	}

	@Override
	public void addResourceHandlers(ResourceHandlerRegistry registry) {
		// TODO Auto-generated method stub
//		WebMvcConfigurer.super.addResourceHandlers(registry);
		registry.addResourceHandler("/img/**").addResourceLocations("/WEB-INF/img/");
		
	}

//	public void configureViewResolvers(ViewResolverRegistry registry) {
//		// TODO Auto-generated method stub
//		WebMvcConfigurer.super.configureViewResolvers(registry);
//		registry.jsp("/WEB-INF/admin/",".jsp");
//		
//	}
	
	public void configurePathMatch(PathMatchConfigurer configurer) {
	    configurer.setUseSuffixPatternMatch(false)
	              .setUseTrailingSlashMatch(true);
	}
}
