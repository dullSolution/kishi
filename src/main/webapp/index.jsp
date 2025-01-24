<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<style type="text/css">
/* From Uiverse.io by alexroumi */
button {
	padding: 15px 25px;
	border: unset;
	border-radius: 15px;
	color: #212121;
	z-index: 1;
	background: #e8e8e8;
	position: relative;
	font-weight: 1000;
	font-size: 17px;
	-webkit-box-shadow: 4px 8px 19px -3px rgba(0, 0, 0, 0.27);
	box-shadow: 4px 8px 19px -3px rgba(0, 0, 0, 0.27);
	transition: all 250ms;
	overflow: hidden;
}

button::before {
	content: "";
	position: absolute;
	top: 0;
	left: 0;
	height: 100%;
	width: 0;
	border-radius: 15px;
	background-color: #212121;
	z-index: -1;
	-webkit-box-shadow: 4px 8px 19px -3px rgba(0, 0, 0, 0.27);
	box-shadow: 4px 8px 19px -3px rgba(0, 0, 0, 0.27);
	transition: all 250ms
}

button:hover {
	color: #e8e8e8;
}

button:hover::before {
	width: 100%;
}
</style>
<meta charset="UTF-8">
<title>Index</title>
</head>
<body>
	<div>
		<h1>${message }</h1><br>
	</div>
	<div>
		<button onclick="show()">绩效展示</button><br>
		<button onclick="go()">绩效填入</button><br>
		<button onclick="about()">About us</button>
	</div>
	<!--  	<a href="/Java2Kpl/world" >绩效展示</a>
	<a href="/Java2Kpl/Go2fill">绩效填入</a>
	<a href="/Java2Kpl/about">About us</a> -->
	<a href="/Java2Kpl/deleted2deleted">调用存储过程</a>
</body>
<script type="text/javascript">
	function show() {

		window.location.href = "/Java2Kpl/world"
	}
	function go() {

		window.location.href = "/Java2Kpl/Go2fill"
	}
	function about() {

		window.location.href = "/Java2Kpl/about"
	}
</script>
</html>