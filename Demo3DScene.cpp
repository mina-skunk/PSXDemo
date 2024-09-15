#include "psyqo/fixed-point.hh"
#include "Demo3DScene.hh"
#include "Render3D.hh"

using namespace psyqo::fixed_point_literals;

void Demo3DScene::start(Scene::StartReason reason) {
  Render3D::init();

  camera.position.x = 0.0_fp;
  camera.position.y = 0.0_fp;
  Render3D::set_camera(&camera);
  
  plane.position.x = 0.0_fp;
  plane.position.y = 0.0_fp;
  plane.position.z = 200.0_fp;
  plane.size.x = 200.0_fp;
  plane.size.y = 200.0_fp;
}

void Demo3DScene::frame() {
  gpu().clear({{ .r=0, .g=0, .b=0 }});
  font->print(gpu(), "3D", {{.x = 16, .y = 64}}, {{.r=255, .g=255, .b=255}});

  // TODO render
  Render3D::render_plane(&plane);
  plane.primitive.setColor({{ .r=100, .g=100, .b=100 }});
  gpu().sendPrimitive(plane.primitive);
}

void Demo3DScene::teardown(psyqo::Scene::TearDownReason) {
  
}
