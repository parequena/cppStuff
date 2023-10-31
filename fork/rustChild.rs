use std::env;

fn main()
{
   let args: Vec<String> = env::args().collect();
   let args_size = args.len();

   let mut n_times = 1;
   if args_size > 1
   {
      n_times = args[1].parse().unwrap();
   }

   let indexes = 0..(n_times);
   for i in indexes
   {
      println!("{} | Hello from rust", i)
   }
}