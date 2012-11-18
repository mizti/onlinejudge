#encoding: utf-8
require 'rspec'
require './a'

describe ZeroCounter do
  it "should return the num of prime factor 2" do
    zc = ZeroCounter.new(19)
    zc.count_num_of_primes(2).should == 16
  end
  it "should return the num of zeros of factorial" do
    zc = ZeroCounter.new(19)
    zc.num_zero.should == 3
  end
  it "should return the num of zeros of factorial" do
    zc = ZeroCounter.new(45)
    zc.num_zero.should == 10
  end
  it "should return the num of zeros of factorial" do
    zc = ZeroCounter.new(50)
    zc.num_zero.should == 12
  end
end
