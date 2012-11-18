# encoding: utf-8
class ZeroCounter
  attr_accessor:num 
  attr_accessor:num_zero
  def initialize(i)
    @num = i
    @num_zero = [count_num_of_primes(2), count_num_of_primes(5)].min
    p @num_zero
 end

  def count_num_of_primes(prime)
    num_pf = 0
    i = prime
    while @num / i > 0 do
      num_pf += @num / i
      i = i * prime 
    end
    return num_pf
  end
end

while (line = gets) do
  if line.to_i != 0 then
    ZeroCounter.new(line.to_i)
  end
end
