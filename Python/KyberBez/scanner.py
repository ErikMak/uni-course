from scapy.all import IP, TCP, sr1, conf
import socket
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
import argparse

socket.setdefaulttimeout(0.1)



def scan_port(ip, port):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        result = s.connect_ex((ip, port))
        return port, result == 0 


def parse_range(range_string):
    try:
        start, end = map(int, range_string.split('-'))
        if start > end:
            raise ValueError("Некорректный диапазон")
        return range(start, end + 1)
    except ValueError as e:
        raise argparse.ArgumentTypeError(f"Неверный формат диапазона: {range_string}")


def scan_ports(ip, range):
    open_ports = []
    with ThreadPoolExecutor(max_workers=100) as executor:
        futures = {executor.submit(scan_port, ip, port): port for port in range}
        for future in as_completed(futures):
            port, is_open = future.result()
            if is_open:
                open_ports.append(port)
    return open_ports

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Scanner")

    parser.add_argument("-t", "--target", dest="target", required=True, help="IP цели")
    parser.add_argument('-p', '--port', dest="range", type=parse_range, required=False,
                    help="Введите диапазон портов в формате '1-5000'")
    start_port = 1
    end_port = 65535

    args = parser.parse_args()

    start_time=time.time()

    open_ports = scan_ports(args.target, args.range)
    print(f"Открытые порты: {open_ports}")
    print(f"Время выполнения: {time.time() - start_time:.2f} секунд")