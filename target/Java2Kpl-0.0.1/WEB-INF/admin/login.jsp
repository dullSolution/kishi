<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>登录界面</title>
</head>
<body>
<div class="loginmanage">
	<div class="py-container">
		<h4 class="manage-title">登录测试</h4>
		<div class="loginform">
			<ul class="sui-nav nav-tabs tab-wraped">
				<li class="active">
					<h3>账户登录</h3>
				</li>
			</ul>
			<div class="tab-content tab-wraped">
				<span style="color: red">${msg}</span>
				<div id="profile" class="tab-pane active">
					<form action="${pageContext.request.contextPath }/login" method="post" id="loginform" class="sui-form">
						<div class="input-prepend">
							<span class="add-on loginname">用户名</span>
							<input type="text" placeholder="账号" class="span2 input-xfat" name="username">
						</div>
						<div class="input-prepend">
							<span class="add-on password">密码</span>
							<input type="text" placeholder="密码" class="span2 input-xfat" name="password">
						</div>
						<div class="logined">
							<a class="sui-btn btn-block btn-xlarge btn-danger" href="javascript:document:loginform.submit();" target="_self">登&nbsp;&nbsp;录</a>
						</div>
					</form>
				</div>
			</div>
		</div>
	</div>
</div>
<a href="${pageContext.request.contextPath }/hello">hello</a>
</body>
<script type="text/javascript">
	var _topWin =window;
	while(_topWin!=_topWin.parent.window){
		_topWin = _topWin.parent.window;
		
	}
	if(window != _topWin)
		_topWin.document.location.href="${pageContext.request.contextPath}/index.jsp";
</script>
</html>