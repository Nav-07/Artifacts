#pragma once

class LevelConfig {
public:
    const int mLevelWidth = 640*5;
    const int mLevelHeight = 480*5;
    const int mArtifactCount = 150;
    const int mTime = 120;
    
    int mCollected = 0;
    int mElapsed = 0;
};
