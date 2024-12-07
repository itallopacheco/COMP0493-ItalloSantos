

def task1(file):
    T = ""
    with open(file, 'r') as f:
        for line in f:
            line = line.strip()

            if line.startswith('.......'):
                break

            T += line + " "

    return T


filename = "teste.txt"  # Substitua pelo nome do arquivo
result = task1(filename)
print(result)


def find_substring_location(T, P):
    posicoes = []
    comeco = 0
    while comeco < len(T):
        pos = T.find(P, comeco)
        if pos == -1:
            posicoes.append(-1)
            break
        posicoes.append(pos)
        comeco = pos + 1
    return posicoes

T = 'I love CS3233 Competitive Programming. i also love AlGoRiThM'
P = 'fasdasfasd'
print(find_substring_location(T,P))

def task_3(T):
    result = ""
    digitos = 0
    vogais = 0
    consoantes = 0

    for char in T:
        if 'A' <= char <= 'Z':
            result += chr(ord(char) + 32)
        else:
            result += char

        if char.isdigit():
            digitos += 1
        elif char.isalpha():
            if char in 'aeiou':
                vogais += 1
            else:
                consoantes += 1

    return result, digitos, vogais, consoantes

resultado, nro_digitos, nro_vogais, consoantes = task_3(T)
print(resultado, nro_digitos, nro_vogais, consoantes)


def task_4(T):
    tokens = T.replace('.', ' ').split()

    return sorted(tokens)

print(task_4(resultado))


def most_frequent_word(T):
    tokens = task_4(T)
    freq = {}

    for token in tokens:
        if token in freq:
            freq[token] += 1
        else:
            freq[token] = 1

    return  max(freq.items(), key=lambda x: x[1])



print(most_frequent_word(resultado))


def task_6():
    ...