def hooks_validation(data: str) -> bool:
    """
    Валидность скобок

    Дана строка data, состоящая только из символов “{“, “}”, “[“, “]”, “(“, “)”.
    Программа должна вывести True, в том случае если все открытые скобки закрыты.

    Например: “[()]{}”, все открытые скобки закрыты закрывающимися скобками, потому вывод будет True.
    В случае же, если строка будет похожа на: “{{{}”, то вывод будет False, т.к. не все открытые скобки закрыты.
    """

    opened_hooks = set()
    opened_hooks.add("[")
    opened_hooks.add("{")
    opened_hooks.add("(")

    hooks = {
        "[": "]",
        "{": "}",
        "(": ")"
    }

    stack = []
    for i in range(0, len(data)):
        if opened_hooks.__contains__(data[i]):
            stack.append(data[i])
        else:
            if len(stack) == 0:
                return False
            last_opened = stack.pop()
            if hooks[last_opened] != data[i]:
                return False
    return len(stack) == 0
