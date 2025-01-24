<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>绩效填入</title>
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

.card {
	width: 250px;
	background: rgb(44, 44, 44);
	font-family: "Courier New", Courier, monospace;
	border-top-left-radius: 12px;
	border-top-right-radius: 12px;
	border-bottom-left-radius: 4px;
	border-bottom-right-radius: 4px;
	overflow: hidden;
}

.card__title {
	color: white;
	font-weight: bold;
	padding: 5px 10px;
	border-bottom: 1px solid rgb(167, 159, 159);
	font-size: 0.95rem;
}

.card__data {
	font-size: 0.8rem;
	display: flex;
	justify-content: space-between;
	border-right: 1px solid rgb(203, 203, 203);
	border-left: 1px solid rgb(203, 203, 203);
	border-bottom: 1px solid rgb(203, 203, 203);
}

.card__right {
	width: 60%;
	border-right: 1px solid rgb(203, 203, 203);
}

.card__left {
	width: 40%;
	text-align: end;
}

.item {
	padding: 3px 0;
	background-color: white;
}

.card__right .item {
	padding-left: 0.8em;
}

.card__left .item {
	padding-right: 0.8em;
}

.item:nth-child(even) {
	background: rgb(234, 235, 234);
}
</style>
</head>
<body>
	<div align="center">
		<div id="question" class="card">
			<table>
				<thead>
					<tr class="card__title">
						<th>序号</th>
						<th>问题描述</th>
						<th>数值填入</th>
					</tr>
				</thead>
				<tbody>
					<div class="card__left">
						<tr class="item">
							<td>1</td>
							<td>问题1</td>
							<td><input type="text" class="fillin"></td>
						</tr>
						<tr class="item">
							<td>2</td>
							<td>问题2</td>
							<td><input type="text" class="fillin"></td>
						</tr>
						<tr class="item">
							<td>3</td>
							<td>问题3</td>
							<td><input type="text" class="fillin"></td>
						</tr>
						<tr class="item">
							<td>4</td>
							<td>问题4</td>
							<td><input type="text" class="fillin"></td>
						</tr>
						<tr class="item">
							<td>5</td>
							<td>问题5</td>
							<td><input type="text" class="fillin"></td>
						</tr>
					</div>
				</tbody>
			</table>
		</div>
		<div id="commitForm" class="form-container">
			<form action="/Java2Kpl/Goat2DB" method="post" class="form">
				<div class="logo-container">填写绩效</div>

				<div class="form=group">
					<label for="name">姓名</label><input type="text" id="name"
						name="name" placeholder="Enter you name"> <br> <label
						for="department">部门</label><input type="text" id="department"
						name="department" placeholder="Enter you department"> <br>
					<label>绩效</label> <input type="text" readonly="readonly" id="goat"
						name="goat">
				</div>
				<input type="button" onclick="comput()" value="统计"> <input
					type="submit" value="上传" class="form-submit-btn">
			</form>
		</div>

		<div>
			<button onclick="back()">返回首页</button>
		</div>
	</div>
</body>
<script type="text/javascript">
	var table = document.querySelector('table');
	var inputs = table.querySelectorAll('input');
	var goat = document.getElementById('goat');

	function comput() {
		var sum = 0

		inputs.forEach(function(input) {
			var num = parseFloat(input.value)

			if (!isNaN(num)) {
				sum += num
			}
		})

		console.log("sum = " + sum)
		goat.setAttribute('value', sum)
	}

	function back() {

		window.location.href = "/Java2Kpl"
	}
</script>
</html>