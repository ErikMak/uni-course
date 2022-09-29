/* 
  Author: ErikMak
  Задание №1 лабораторной №3 
*/
function checkConfirmPass(form) {
	const input = form.querySelector('#confirm-pass');
	const value = input.value.trim();
	const password = form.querySelector('#pass').value.trim();
	
	if(password === value && value != '') {
		setSuccessFor(input.parentElement);
	} else {
		setErrorFor(input.parentElement);
	}
}

function validateForm() {
	const formHandle = document.querySelector('#reg-form');


	checkConfirmPass(formHandle);
}

function setErrorFor(form_group) {
	form_group.classList.remove('success');
}

function setSuccessFor(form_group) {
	form_group.classList.add('success');
}


// BUTTON CLICK EVENT
document.addEventListener('DOMContentLoaded', function() {
	console.log('Скрипт написан https://github.com/ErikMak');
	let btn = document.querySelector('.submit-btn');

	btn.addEventListener('click', e => {
		e.preventDefault();

		validateForm();
	});
});