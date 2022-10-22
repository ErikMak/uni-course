/* 
  Author: ErikMak
  Задание №2 лабораторной №3 
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
		// COLLECT ALL DATA
		const text = [
			formHandle.querySelector('#username').value,
			formHandle.querySelector('input[name="gender"]:checked').value,
			formHandle.querySelector('#career').value,
			formHandle.querySelector('#email').value,
			formHandle.querySelector('#pass').value
		].join('<br>');

		showPopup(text);
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

// BUTTON CLICK EVENT
document.addEventListener('DOMContentLoaded', function() {
	console.log('Скрипт написан https://github.com/ErikMak');
	let btn = document.querySelector('#submit-btn');
	btn.addEventListener('click', e => {
		e.preventDefault();

		validateForm();
	});

	document.querySelector('#popup-close').addEventListener('click', e => {
		e.preventDefault();

		closePopup();
	});
});