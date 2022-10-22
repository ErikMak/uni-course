/* 
  Author: ErikMak
  Задание №4 лабораторной №3 
*/

// IMGS DATA
const imgs = [
	{source: 'image_1.jpg'},
	{source: 'image_2.jpg'},
	{source: 'image_3.jpg'},
	{source: 'image_4.jpg'},
	{source: 'image_5.jpg'}
]

document.addEventListener('DOMContentLoaded', function() {
	console.log('Скрипт написан https://github.com/ErikMak');
	let img = document.querySelector('#imgContainer');

	let index = 0;

	img.addEventListener('click', function (){
		if (index < imgs.length-1) {
			index++;
		} else {
			index = 0;
		}

		let img = document.querySelector('#imgContainer');
		let path = imgs[index].source;
		img.src = path;
		return index;
	});
});