<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<style type="text/css">
.form-container {
	max-width: 400px;
	background-color: #fff;
	padding: 32px 24px;
	font-size: 14px;
	font-family: inherit;
	color: #212121;
	display: flex;
	flex-direction: column;
	gap: 20px;
	box-sizing: border-box;
	border-radius: 10px;
	box-shadow: 0px 0px 3px rgba(0, 0, 0, 0.084), 0px 2px 3px
		rgba(0, 0, 0, 0.168);
}

.form-container button:active {
	scale: 0.95;
}

.form-container .logo-container {
	text-align: center;
	font-weight: 600;
	font-size: 18px;
}

.form-container .form {
	display: flex;
	flex-direction: column;
}

.form-container .form-group {
	display: flex;
	flex-direction: column;
	gap: 2px;
}

.form-container .form-group label {
	display: block;
	margin-bottom: 5px;
}

.form-container .form-group input {
	width: 100%;
	padding: 12px 16px;
	border-radius: 6px;
	font-family: inherit;
	border: 1px solid #ccc;
}

.form-container .form-group input::placeholder {
	opacity: 0.5;
}

.form-container .form-group input:focus {
	outline: none;
	border-color: #1778f2;
}

.form-container .form-submit-btn {
	display: flex;
	justify-content: center;
	align-items: center;
	font-family: inherit;
	color: #fff;
	background-color: #212121;
	border: none;
	width: 100%;
	padding: 12px 16px;
	font-size: inherit;
	gap: 8px;
	margin: 12px 0;
	cursor: pointer;
	border-radius: 6px;
	box-shadow: 0px 0px 3px rgba(0, 0, 0, 0.084), 0px 2px 3px
		rgba(0, 0, 0, 0.168);
}

.form-container .form-submit-btn:hover {
	background-color: #313131;
}

.form-container .link {
	color: #1778f2;
	text-decoration: none;
}

.form-container .signup-link {
	align-self: center;
	font-weight: 500;
}

.form-container .signup-link .link {
	font-weight: 400;
}

.form-container .link:hover {
	text-decoration: underline;
}
</style>
<meta charset="UTF-8">
<title>绩效展示</title>
<script src="https://unpkg.com/mathlive"></script>
</head>
<script type="text/javascript">
	
</script>
<body>
	<h2 align="center">绩效展示</h2>
	<div id="toSearch" align="center">
		<form class="form">
			<div class="form-group">

				<input type="text" placeholder="Enter your name" required=""
					id="ipu">
			</div>

			<input class="form-submit-btn" onclick="change()" type="button"
				value="search">
		</form>
	</div>

	<div align="center">
		<!--  	<math-field id="formula"></math-field>  -->
		<iframe src="showTable" id="frr"></iframe>
	</div>
	<div>
		<button onclick="back()">返回首页</button>
	</div>
</body>

<script type="text/javascript">
	function change() {
		var frr = document.getElementById("frr")
		var ipu = document.getElementById("ipu")

		if (ipu.value == "" || ipu.value == null) {
			frr.src = "select"
		} else {
			frr.src = "select?name=" + ipu.value
		}
	}

	function back() {

		window.location.href = "/Java2Kpl"
	}
</script>
</html>