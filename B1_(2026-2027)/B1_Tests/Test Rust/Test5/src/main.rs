// Command to compile the program faster: " cargo run --features bevy/dynamic_linking " 

#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use bevy::prelude::*;
use bevy::window::WindowResolution;


const PLAYER_SIZE: f32 = 50.0;

#[derive(Component)]
struct Player;

#[derive(Component)] 
struct Speed(f32);



fn main() { 
    App::new() 
    .add_plugins(DefaultPlugins.set(WindowPlugin {
            primary_window: Some(Window {
                title: "Test application en Rust avec Bevy".into(), 
                resolution: WindowResolution::new(800, 600),
                ..default()
            }),
            ..default()
        }))
    .init_resource::<GameSaveData>()
    .add_systems(Startup, setup) 
    .add_systems(Update, move_player)
    .add_systems(Last, save_on_exit) 
    .run(); 
} 



fn setup(mut commands: Commands) {
    commands.spawn(Camera2d);

    commands.spawn((
        Sprite::from_color(Color::srgb(0.2, 0.8, 0.2), Vec2::splat(PLAYER_SIZE)),
        Transform::from_xyz(0.0, 0.0, 0.0),
        Player,
        Speed(300.0),
    ));
}

fn move_player(
    keyboard_input: Res<ButtonInput<KeyCode>>,
    time: Res<Time>,
    window: Single<&Window>,
    mut query: Query<(&mut Transform, &Speed), With<Player>>,
) {
    let half_w = ((window.width() - PLAYER_SIZE) * 0.5).max(0.0);
    let half_h = ((window.height() - PLAYER_SIZE) * 0.5).max(0.0);

    for (mut transform, speed) in &mut query {
        let mut direction = Vec2::ZERO;

        if keyboard_input.pressed(KeyCode::ArrowLeft) {
            direction.x -= 1.0;
        }
        if keyboard_input.pressed(KeyCode::ArrowRight) {
            direction.x += 1.0;
        }
        if keyboard_input.pressed(KeyCode::ArrowUp) {
            direction.y += 1.0;
        }
        if keyboard_input.pressed(KeyCode::ArrowDown) {
            direction.y -= 1.0;
        }

        let velocity = direction.normalize_or_zero() * speed.0 * time.delta_secs();

        transform.translation.x = (transform.translation.x + velocity.x).clamp(-half_w, half_w);
        transform.translation.y = (transform.translation.y + velocity.y).clamp(-half_h, half_h);
    }
}

fn save_on_exit(
    mut exit_messages: MessageReader<AppExit>, 
    save_data: Res<GameSaveData>,
) {
    
    if exit_messages.read().next().is_some() {
        if let Ok(json) = serde_json::to_string_pretty(&*save_data) {
            let _ = fs::write("savegame.json", json);
            info!("Partie sauvegardée avec succès avant la fermeture.");
        }
    }
}