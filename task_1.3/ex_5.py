def binary_multiply(bin_one: str, bin_two: str) -> str:
    """
    Умножить два бинарных числа в формате строк
    На вход подаются две строки binOne и binTwo, содержащие бинарные числа.
    Необходимо вывести их бинарное произведение в формате строки.
    """

    dec_mul = int(bin_one, 2) * int(bin_two, 2)
    return bin(dec_mul).split("b")[1]
