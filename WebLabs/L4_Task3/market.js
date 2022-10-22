/* 
  Author: ErikMak
  Задание №3 лабораторной №4
*/
function getCartData(){
	return JSON.parse(localStorage.getItem('cart'));
}

function addToCart(item) {
	// Загрузка данных корзины или создание пустого массива
	let cartData = getCartData();
	if(!cartData) {
		cartData = [];
	}

	// Объект покупки
	const itemID = item.querySelector('.add_item').getAttribute('data-id');
	const itemPrice = parseInt(item.querySelector('.item_price').innerHTML);
	const itemTitle = item.querySelector('.item_title').innerHTML;
	// Если объект добавлен - увеличить его количество в корзине
	for(let i = 0; i < cartData.length; i++) {
		if(cartData[i].itemID === itemID) {
			cartData[i].quantity++;
			// Изменить итоговую цену
			cartData[i].itemPrice = itemPrice * cartData[i].quantity;
			// Загрузить в LS
			uploadCartData(cartData);
			return false;
		}
	}

	let cartItem = {
		parentBox: item,
		itemID: itemID,
		itemTitle: itemTitle,
		itemPrice: itemPrice,
		quantity: 1
	};

	// Добавить в корзину
	cartData.push(cartItem);
	// Загрузить в LS
	uploadCartData(cartData);
}

function uploadCartData(data) {
	localStorage.setItem('cart', JSON.stringify(data));
}

function openCart() {
	const cart_content = document.getElementById('cart_content');
	// Загрузка данных с корзины
	let cartData = getCartData();
	let totalItems = '';
	let totalPrice = 0;
	let totalQuantity = 0;

	if(cartData !== null){
		totalItems = '<table class="shopping_list"><tr><th>Наименование</th><th>Цена</th><th>Кол-во</th></tr>';
		for(let i = 0; i < cartData.length; i++){
			totalItems += '<td>' + cartData[i].itemTitle + '</td>';
			// + подсчет всей суммы
			totalItems += '<td>' + cartData[i].itemPrice + '</td>';
			totalPrice += cartData[i].itemPrice;
			// + подсчет кол-ва всех товаров
			totalItems += '<td>' + cartData[i].quantity + '</td>';
			totalQuantity +=  cartData[i].quantity;

			totalItems += '</tr>';
		}
		totalItems += '<tr><td></td><td><b>Итого: </b>' + totalPrice + '</td>\
		<td><b>Общее количество: </b>' + totalQuantity + '</td></tr>';
		totalItems += '<table>';
		cart_content.innerHTML = totalItems;
	} else {
		// если в корзине пусто, то сигнализируем об этом
		cart_content.innerHTML = 'В корзине пусто!';
	}
}

// EVENTS 
document.addEventListener('DOMContentLoaded', function() {
	console.log('Скрипт написан https://github.com/ErikMak');
	const checkout_btn = document.querySelector('#checkout');
	const clear_cart_btn = document.querySelector('#clear_cart');
	const purchase_btns = document.querySelectorAll('.add_item');

	checkout_btn.addEventListener('click', e => {
		e.preventDefault();

		openCart();
	});

	clear_cart_btn.addEventListener('click', e => {
		e.preventDefault();

		const cart_content = document.getElementById('cart_content');
		localStorage.removeItem('cart');
		cart_content.innerHTML = 'Корзина очищена!';
	});

	purchase_btns.forEach(function (btn) {
		btn.addEventListener('click', e => {
			e.preventDefault();

			btn.disabled = true

			const itemHandle = btn.parentElement;
			addToCart(itemHandle);

			btn.disabled = false;
		}); 
	});
});