fn main() {
    
    let mut message = String::from("Ceci est un");


    let message2 = &mut message;
    message2.push_str(" Test");


    println!("{}", message2);
}
