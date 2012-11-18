def parse_args(tokens)
  left = 0
  right = 0

  token = tokens.shift
  token = tokens.shift while token == ""
  case token
  when "+"
    left = add(tokens)
  when "-"
    left = subtract(tokens)
  when "*"
    left = multiply(tokens)
  else
    left = token.to_i
  end

  token = tokens.shift
  token = tokens.shift while token == ""
  case token
  when "+"
    right = add(tokens)
  when "-"
    right = subtract(tokens)
  when "*"
    right multiply(tokens)
  else
    right = token.to_i
  end
  return left, right
end

def add(tokens)
  left, right = parse_args(tokens)
  return left + right
end

def subtract(tokens)
  left, right = parse_args(tokens)
  return left - right
end

def multiply(tokens)
  left, right = parse_args(tokens)
  return left * right
end

tokens = STDIN.gets.chomp.split(/[ \(\)]/)
token = tokens.shift
token = tokens.shift while token == ""
result = 0
case token
when "+"
    result = add(tokens)
when "-"
    result = subtract(tokens)
when "*"
    result = multiply(tokens)
else
    result = token.to_i
end

puts result


