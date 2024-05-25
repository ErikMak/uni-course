from pydantic import BaseModel
from typing import List, Union
import json
from pathlib import Path

class Geometry(BaseModel):
  type: str
  coordinates: List[List[List[Union[float, float]]]]

class Properties(BaseModel):
  objectType: str


class Feature(BaseModel):
  type: str
  id: str
  geometry: Geometry
  properties: Properties

class MyModel(BaseModel):
  type: str
  features: List[Feature]

inPath = Path('4.geojson')
model = MyModel.model_validate_json(inPath.read_text())
outPath = Path('output.geojson')
outPath.write_text(model.model_dump_json(exclude_none=True))

inPath = Path('output.geojson')
content = inPath.read_text()
data = json.loads(content)
print(data)