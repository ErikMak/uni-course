/* 
  Author: ErikMak
  Задание №2 лабораторной №4
*/
function checkEmail(form) {
	let valid = false;

	const input = form.querySelector('#email');
	const value = input.value.trim();
	const rv_email = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/;
	
	if(value != '' && rv_email.test(value)) {
		valid = true;
		setSuccessFor(input.parentElement);
	} else {
		setErrorFor(input.parentElement, 'Некорректный E-mail!');
	}

	return valid;
}

function checkUsername(form) {
	let valid = false;

	const input = form.querySelector('#username');
	const value = input.value.trim();
	const rv_username = /^(?=.{1,24}$)[a-zA-Z][a-zA-Z0-9]*(?: [a-zA-Z0-9]+)*$/;
	
	if(value != '' && rv_username.test(value)) {
		valid = true;
		setSuccessFor(input.parentElement);
	} else {
		setErrorFor(input.parentElement, 'Некорректное имя пользователя!');
	}

	return valid;
}

function checkPassword(form) {
	let valid = false;

	const input = form.querySelector('#pass');
	const value = input.value.trim();
	const rv_pass = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[a-zA-Z\d]{6,20}$/;
	
	if(value != '' && rv_pass.test(value)) {
		valid = true;
		setSuccessFor(input.parentElement);
	} else {
		setErrorFor(input.parentElement, 'Некорректный пароль!');
	}

	return valid;
}

function checkConfirmPass(form) {
	let valid = false;

	const input = form.querySelector('#confirm-pass');
	const value = input.value.trim();
	const password = form.querySelector('#pass').value.trim();
	
	if(value == '') {
		setErrorFor(input.parentElement, 'Подтвердите свой пароль!');
	} else if (password != value) {
		setErrorFor(input.parentElement, 'Пароль не соотвествует!');
	} else {
		valid = true;
		setSuccessFor(input.parentElement);
	}

	return valid;
}

function checkGender(form) {
	let valid = false;

	const input = form.querySelector('input[name="gender"]');
	const p = input.parentElement;
	const checked = input.checked;
	
	if(checked == false) {
		setErrorFor(p.parentElement, 'Выберете свой пол!');
	} else {
		p.parentElement.classList.remove('success', 'error');
		valid = true;
	}

	return valid;
}

function validateForm() {
	const formHandle = document.querySelector('#reg-form');

	let isUsernameValid = checkUsername(formHandle),
		isEmailValid = checkEmail(formHandle),
		isPasswordValid = checkPassword(formHandle),
		isConfirmPassValid = checkConfirmPass(formHandle),
		isGenderValid = checkGender(formHandle);

	let isFormValid = isUsernameValid &&
		isEmailValid && 
		isPasswordValid &&
		isGenderValid && 
		isConfirmPassValid;

	if(isFormValid) {
		const username = formHandle.querySelector('#username').value;
		const password = formHandle.querySelector('#pass').value;

		localStorage.setItem('username', username);
		localStorage.setItem('pass', password);
		localStorage.setItem('logged_in', true);
	}
}

function setErrorFor(form_group, msg) {
	form_group.classList.remove('success', 'error');
	form_group.classList.add('error');

	const small = form_group.querySelector('small');
	small.innerHTML = msg;
}

function setSuccessFor(form_group) {
	form_group.classList.remove('success', 'error');
	form_group.classList.add('success');
}

// POPUP
function showPopup(msg) {
	document.querySelector('#overlay').classList.add('is-visible');
	document.querySelector('#popup').classList.add('is-visible');

	const text = document.getElementById('popup').querySelector('p');
	text.innerHTML = msg;
}

function closePopup() {
	document.querySelector('#overlay').classList.remove('is-visible');
	document.querySelector('#popup').classList.remove('is-visible');
}


// COOKIES
function getCookie(name) {
	let searchName = name + "=";
  let cookies = document.cookie.split(';');
  for(let i = 0; i < cookies.length; i++) {
      let c = cookies[i];
      while (c.charAt(0) == ' ')
          c = c.substring(1, c.length);
      if(c.indexOf(searchName) == 0)
          return c.substring(searchName.length, c.length);        
  }
  return null;
}

function deleteCookie(name) {
	if(getCookie(name)) {
    document.cookie = name + "=;expires=Thu, 01 Jan 1970 00:00:01 GMT";
  }
}

function deleteAllCookies() {
	if(document.cookie != '') {
		let cookies = document.cookie.split("; ");
		for (i in cookies) {
			let cookie_name = /^[^=]+/.exec(cookies[i])[0];
		  deleteCookie(cookie_name);    
		}
	}
}


// EVENTS
document.addEventListener('DOMContentLoaded', function() {
	console.log('Скрипт написан https://github.com/ErikMak');
	let btn = document.querySelector('#submit-btn');
	let clear_cookie = document.querySelector('#cookie-btn');


	// WELCOME MESSAGE
	if(localStorage.getItem('logged_in')) {
		const text = document.getElementById('top').querySelector('h2');
		const username = localStorage.getItem('username');
		const password = localStorage.getItem('pass');
		// Приветсвенное сообщение
		text.innerHTML = 'Добро пожаловать, '+username;

		// Поля 
		const formHandle = document.querySelector('#reg-form');
		const username_input = formHandle.querySelector('#username');
		const password_input = formHandle.querySelector('#pass');

		// Подстановка в поля
		username_input.value = username;
		password_input.value = password;
	}

	btn.addEventListener('click', e => {
		e.preventDefault();

		validateForm();
	});

	document.querySelector('#popup-close').addEventListener('click', e => {
		e.preventDefault();

		closePopup();
	});
});