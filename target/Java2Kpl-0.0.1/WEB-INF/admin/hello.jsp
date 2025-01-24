<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<style type="text/css">
/* From Uiverse.io by gharsh11032000 */ 
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
  box-shadow: 0px 0px 3px rgba(0, 0, 0, 0.084), 0px 2px 3px rgba(0, 0, 0, 0.168);
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
  box-shadow: 0px 0px 3px rgba(0, 0, 0, 0.084), 0px 2px 3px rgba(0, 0, 0, 0.168);
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
<title>你好世界</title>
<style type="text/css">
/* From Uiverse.io by Rodrypaladin */ 
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


<div class="card">
  <div class="card__title">table</div>
  <div class="card__data">
    <div class="card__right">
      <div class="item">id</div>
      <div class="item">name</div>
      <div class="item">date</div>
      <div class="item">active</div>
    </div>
    <div class="card__left">
      <div class="item">int</div>
      <div class="item">varchar</div>
      <div class="item">datetime</div>
      <div class="item">boolean</div>
    </div>
  </div>
</div>


<div class="form-container">
      <div class="logo-container">
        Forgot Password
      </div>

      <form class="form">
        <div class="form-group">
          <label for="email">Email</label>
          <input type="text" id="email" name="email" placeholder="Enter your email" required="">
        </div>

        <button class="form-submit-btn" type="submit">Send Email</button>
      </form>

      <p class="signup-link">
        Don't have an account?
        <a href="#" class="signup-link link"> Sign up now</a>
      </p>
    </div>
	<h1>HELLO</h1>
	
</body>
</html>