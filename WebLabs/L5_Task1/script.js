/* 
  Author: ErikMak
  Задание №1 лабораторной №5 
*/
document.addEventListener('DOMContentLoaded', function() {
	console.log('Скрипт написан https://github.com/ErikMak');
	let formHandle = document.querySelector('#validate-it');

	formHandle.addEventListener('submit', function(e) {
		if(!formHandle.checkValidaty()) {
			e.preventDefault();
			e.stopPropagation();
		}

		formHandle.classList.add('was-validated');
	});
});